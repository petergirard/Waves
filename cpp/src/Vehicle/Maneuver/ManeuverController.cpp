//
// Created by Peter on 6/4/2024.
//

#include "ManeuverController.h"
#include "Pid/PidCalculator.h"

void ManeuverController::updateControls(const ManeuverState& maneuverState,
                                        const NavigationStatus& navigationStatus,
                                        const TimePoint& currentTime) {

    depthPidOutputs = PidCalculator::calculate(navigationStatus.depthError, currentTime, depthPidOutputs, settings.depthPid);
    double pitchGoal = GenericUtils::boundNumber(depthPidOutputs.value, -1 * std::numbers::pi / 4, std::numbers::pi / 4); // -45 deg to 45 deg.
    double pitchError = pitchGoal - maneuverState.attitude.pitch;

    pitchPidOutputs = PidCalculator::calculate(pitchError, currentTime, pitchPidOutputs, settings.pitchPid);
    yawPidOutputs = PidCalculator::calculate(navigationStatus.yawError, currentTime, yawPidOutputs, settings.yawPid);
    speedPidOutputs = PidCalculator::calculate(navigationStatus.speedError, currentTime, speedPidOutputs, settings.yawPid);

    controls = ManeuverControls(pitchGoal, pitchPidOutputs.value, yawPidOutputs.value, speedPidOutputs.value);
    isStopped = false;
}

void ManeuverController::stop() {
    // Reset
    pitchPidOutputs = PidOutput();
    yawPidOutputs = PidOutput();
    speedPidOutputs = PidOutput();

    controls = ManeuverControls();
    isStopped = true;
}
