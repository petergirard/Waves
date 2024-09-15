//
// Created by Peter on 6/4/2024.
//

#include "PidController.h"
#include "../../Util/MathUtils.h"


bool PidController::isStopped() const {
    return _isStopped;
}

ManeuverControlsState PidController::getControlsState() const {
    return _controlsState;
}

ManeuverGoalsState PidController::getManeuverGoalsState() const {
    return _maneuverGoalsState;
}

void PidController::update(const DriveToManeuver& maneuver,
                           const PhysicalState& physicalState,
                           const double& dt) {
    bool updateIntegral = !_isStopped; // if vehicle was previously stopped, the integral should not be updated.
    _maneuverGoalsState = calculateManeuverGoals(maneuver, physicalState, dt, updateIntegral);

    _pitchPidOutputs = calculatePid(_maneuverGoalsState.pitchError, dt, _pitchPidOutputs, settings.pitchPid, updateIntegral);
    _yawPidOutputs = calculatePid(_maneuverGoalsState.yawError, dt, _yawPidOutputs, settings.yawPid, updateIntegral);
    _speedPidOutputs = calculatePid(_maneuverGoalsState.speedError, dt, _speedPidOutputs, settings.speedPid, updateIntegral);

    _controlsState = ManeuverControlsState(_pitchPidOutputs.value, _yawPidOutputs.value, _speedPidOutputs.value);
    _isStopped = false;
}

void PidController::stop() {
    _controlsState = ManeuverControlsState();
    _maneuverGoalsState = ManeuverGoalsState();
    _isStopped = true;
}

void PidController::reset() {
    _pitchPidOutputs = PidOutput();
    _yawPidOutputs = PidOutput();
    _speedPidOutputs = PidOutput();
    stop();
}

ManeuverGoalsState PidController::calculateManeuverGoals(const DriveToManeuver& driveToManeuver,
                                                         const PhysicalState& physicalState,
                                                         const double& dt,
                                                         const bool& updateIntegral) {
    // TODO: Handle drive from position.

    double yawGoal = physicalState.position.to2D().angleTo(driveToManeuver.toPosition.to2D());
    double depthGoal = driveToManeuver.toPosition.z;
    double speedGoal = driveToManeuver.speed;

    double yawError = MathUtils::boundRadians_NegPiToPi(yawGoal - physicalState.attitude.yaw);
    double depthError = depthGoal - physicalState.position.z;
    double speedError = speedGoal - physicalState.velocityWorldFrame.to2D().magnitude;

    _depthPidOutputs = calculatePid(_maneuverGoalsState.depthError, dt, _depthPidOutputs, settings.depthPid, updateIntegral);
    double pitchGoal = GenericUtils::boundNumber(_depthPidOutputs.value, -1 * std::numbers::pi / 4, std::numbers::pi / 4); // -45 deg to 45 deg.
    pitchGoal *= -1;
    double pitchError = pitchGoal - physicalState.attitude.pitch;

    return {pitchGoal,
            pitchError,
            yawGoal,
            yawError,
            depthGoal,
            depthError,
            speedGoal,
            speedError};
}

PidOutput PidController::calculatePid(const double &error, const double &dt, const PidOutput &lastOutput,
                                      const PidSettings &pidSettings, const bool& updateIntegral) {
    auto integral = updateIntegral ? lastOutput.integral + error * dt : lastOutput.integral;
    auto derivative = (error - lastOutput.error) / dt;

    auto output = pidSettings.kp * error + pidSettings.ki * integral + pidSettings.kd * derivative;

    return {output, error, integral};
}
