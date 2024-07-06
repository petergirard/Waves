//
// Created by Peter on 6/4/2024.
//

#include "ManeuverController.h"
#include "Pid/PidCalculator.h"
#include "../../Util/MathUtils.h"

void ManeuverController::updateControls(const PhysicalState& physicalState,
                                        const MissionState& missionState,
                                        const TimePoint& currentTime) {

    maneuverGoalState = calculateManeuverState(missionState, physicalState);

    depthPidOutputs = PidCalculator::calculate(maneuverGoalState.depthError, currentTime, depthPidOutputs, settings.depthPid);
    double pitchGoal = GenericUtils::boundNumber(depthPidOutputs.value, -1 * std::numbers::pi / 4, std::numbers::pi / 4); // -45 deg to 45 deg.
    pitchGoal *= -1;
    double pitchError = pitchGoal - physicalState.attitude.pitch;

    pitchPidOutputs = PidCalculator::calculate(pitchError, currentTime, pitchPidOutputs, settings.pitchPid);
    yawPidOutputs = PidCalculator::calculate(maneuverGoalState.yawError, currentTime, yawPidOutputs, settings.yawPid);
    speedPidOutputs = PidCalculator::calculate(maneuverGoalState.speedError, currentTime, speedPidOutputs, settings.speedPid);

    controls = ManeuverControlsState(pitchGoal, pitchPidOutputs.value, yawPidOutputs.value, speedPidOutputs.value);
    isStopped = false;
}

void ManeuverController::stop() {
    // Reset
    pitchPidOutputs = PidOutput();
    yawPidOutputs = PidOutput();
    speedPidOutputs = PidOutput();

    controls = ManeuverControlsState();
    isStopped = true;
}

ManeuverGoalsState ManeuverController::calculateManeuverState(const MissionState& missionState, PhysicalState physicalState) {
    double yawGoal = physicalState.position.to2D().angleTo(missionState.activeWaypoint.position);
    double depthGoal = missionState.activeWaypoint.depth;
    double speedGoal = missionState.activeWaypoint.speed;

    double yawError = MathUtils::boundRadians_NegPiToPi(yawGoal - physicalState.attitude.yaw);
    double depthError = depthGoal - physicalState.position.z;
    double speedError = speedGoal - physicalState.velocityWorldFrame.to2D().magnitude;

    return {yawGoal,
            yawError,
            depthGoal,
            depthError,
            speedGoal,
            speedError};
}
