//
// Created by Peter on 6/14/2024.
//

#include "Pilot.h"

MissionExecutionState Pilot::getMissionState() const {
    return _missionEngine.getMissionState();
}

std::optional<ManeuverGoalsState> Pilot::getManeuverGoalsState() const {
    return _maneuverEngine.getManeuverGoalsState();
}

ManeuverControlsState Pilot::getManeuverControlsState() const {
    return _maneuverEngine.getManeuverControlsState();
}

BatteryState Pilot::getBatteryState() const {
    return _batteryManager.batteryState;
}


void Pilot::loadMission(Mission&& mission) {
    missionRepo.loadMission(std::move(mission));
}

void Pilot::setActiveMission(const std::string& missionName) {
    auto mission = missionRepo.getMission(missionName);
    if (mission.has_value()){
        _missionEngine.runMission(mission.value());
        setCurrentWaypointToActiveManeuver();
    }
    else
        throw std::runtime_error("Mission not found in repository.");
}

void Pilot::addCurrentManeuver(std::unique_ptr<ManeuverBase> maneuver) {
    _maneuverEngine.addManeuver(std::move(maneuver));
}

void Pilot::stop() {
    _maneuverEngine.reset();
    _missionEngine.reset();
}

void Pilot::update(const PhysicalState& newState, const TimePoint& time, const double& dt) {
    bool maneuverComplete = _maneuverEngine.update(newState, time, dt);
    if (_missionEngine.isMissionActive() && maneuverComplete){
        _missionEngine.progressWaypoint();
        if (getMissionState().activeMissionState == ActiveMissionState::Finished){
            _maneuverEngine.reset();
        }
        else{
            setCurrentWaypointToActiveManeuver();
        }
    }

    _batteryManager.update(getManeuverControlsState(), dt);
}


void Pilot::setCurrentWaypointToActiveManeuver() {
    auto maneuver = convertWaypointToManeuver(_missionEngine.getMissionState().activeWaypoint, std::nullopt);
    _maneuverEngine.addManeuver(std::move(std::make_unique<DriveToManeuver>(maneuver)));
}

DriveToManeuver Pilot::convertWaypointToManeuver(const Waypoint& nextWp, const std::optional<Waypoint>& previousWp) {
    ManeuverCompletionCriteria completionCriteria{};
    completionCriteria.proximityToGoal = nextWp.successRadius;
    std::optional<Point3D> driveFrom;
    if (previousWp.has_value())
        driveFrom = previousWp.value().position;

    return {completionCriteria, nextWp.position, driveFrom, nextWp.speed};
}

