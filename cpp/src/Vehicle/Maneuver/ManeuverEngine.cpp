//
// Created by Peter on 7/13/2024.
//

#include "ManeuverEngine.h"

bool ManeuverEngine::isUnderPrimitiveControl() const {
    return _primitiveControl.has_value();
}

ManeuverControlsState ManeuverEngine::getManeuverControlsState() const {
    return isUnderPrimitiveControl()
            ? _primitiveControl.value()
            : _pidController.getControlsState();
}

std::optional<ManeuverGoalsState> ManeuverEngine::getManeuverGoalsState() const {
    return isUnderPrimitiveControl()
            ? std::nullopt
            : std::optional<ManeuverGoalsState>(_pidController.getManeuverGoalsState());
}

void ManeuverEngine::addManeuver(std::unique_ptr<ManeuverBase> maneuver) {
    ManeuverWrapper wrapper(std::move(maneuver));
    _maneuverStack.push(std::move(wrapper));
}

void ManeuverEngine::reset() {
    _primitiveControl = ManeuverControlsState();
    _maneuverGoals = std::nullopt;
    _activeManeuver = std::nullopt;
    _pidController.reset();
    _maneuverStack = std::stack<ManeuverWrapper>();
}

bool ManeuverEngine::update(const PhysicalState &physicalState, const TimePoint &time, const double& dt) {
    if (_activeManeuver.has_value()){
        // TODO: Change input to be duration.
        std::chrono::duration<double> duration(dt);
        _activeManeuver.value().runTime += duration;
    }

    if (!_activeManeuver.has_value() || isManeuverComplete(_activeManeuver.value(), physicalState, time)){
        if (_maneuverStack.empty()){
            return true;
        }
        goToNextManeuver();
    }

    if (isUnderPrimitiveControl()){
        return false;
    }

    // Treat rest of maneuvers as DriveToManeuver.
    // ParkManeuver becomes a DriveToManeuver that is just turned on/off based on distance to park point.
    if (auto park = dynamic_cast<ParkManeuver*>(_activeManeuver.value().maneuver.get())){
        if (isInsideParkRadius(*park, physicalState.position)){
            // parking and inside radius.
            _pidController.stop();
            return false;
        }

        auto driveToManeuver = convertParkToDrive(*park);
        auto driveManeuver = convertParkToDrive(*park);
        _pidController.update(driveManeuver, physicalState, dt);
    }
    else if (auto driveToManeuver = dynamic_cast<DriveToManeuver*>(_activeManeuver.value().maneuver.get())) {
        _pidController.update(*driveToManeuver, physicalState, dt);
    } else {
        throw std::runtime_error("Unable to determine type of active maneuver.");
    }

    return false;
}

bool ManeuverEngine::isManeuverComplete(const ManeuverWrapper& wrapper,
                                        const PhysicalState& physicalState, const TimePoint& time) {

    ManeuverCompletionCriteria completionCriteria = wrapper.maneuver->completionCriteria;

    // Check duration
    if (completionCriteria.duration.has_value() && wrapper.runTime > completionCriteria.duration.value()){
        return true;
    }
    // Check time
    if (completionCriteria.completionTime.has_value() && time > completionCriteria.completionTime.value()){
        return true;
    }
    // Check depth
    if (completionCriteria.depthReached.has_value() && physicalState.position.z > completionCriteria.depthReached.value()){
        return true;
    }

    // Check proximity
    if (completionCriteria.proximityToGoal.has_value()){
        auto driveToManeuver = dynamic_cast<DriveToManeuver*>(wrapper.maneuver.get());
        if (driveToManeuver == nullptr){
            // TODO: Log error.
            // Could throw an error but for now return maneuver is complete so maneuver engine doesn't blow up.
            return true;
        }

        if (driveToManeuver->toPosition.to2D().distanceTo(physicalState.position.to2D()) < completionCriteria.proximityToGoal.value()){
            return true;
        }
    }

    // Check perpendicular
    if (completionCriteria.perpendicularToGoal.has_value()){
        // TODO: Implement perpendicular to goal completion criteria.
    }

    return false;
}

bool ManeuverEngine::isInsideParkRadius(const ParkManeuver &parkManeuver, const Point3D& vehiclePosition) {
    return (parkManeuver.parkLocation.to2D() - vehiclePosition.to2D()).magnitude < parkManeuver.parkRadius;
}

DriveToManeuver ManeuverEngine::convertParkToDrive(const ParkManeuver& park) {
    ManeuverCompletionCriteria completionCriteria(park.parkRadius, std::nullopt, std::nullopt, std::nullopt, std::nullopt);
    return {completionCriteria, park.parkLocation, std::nullopt, park.parkSpeed};
}

void ManeuverEngine::goToNextManeuver() {
    _activeManeuver = std::move(_maneuverStack.top());
    _maneuverStack.pop(); // Remove top element

    if (auto primitive = dynamic_cast<PrimitiveManeuver*>(_activeManeuver.value().maneuver.get())){
        _primitiveControl = primitive->controlsState;
        _maneuverGoals.reset();
    }
    else{
        _primitiveControl = std::nullopt;
    }
}