//
// Created by Peter on 6/4/2024.
//

#include "ManeuverController.h"
#include "Pid/PidCalculator.h"

void ManeuverController::updateControls(const NavigationStatus& navigationStatus,
                                        const TimePoint& currentTime) {

    pitchPidOutputs = PidCalculator::calculate(navigationStatus.depthError, currentTime, pitchPidOutputs, settings.pitchPid);
    yawPidOutputs = PidCalculator::calculate(navigationStatus.yawError, currentTime, yawPidOutputs, settings.yawPid);
    speedPidOutputs = PidCalculator::calculate(navigationStatus.speedError, currentTime, speedPidOutputs, settings.yawPid);

    controls = ManeuverControls(pitchPidOutputs.value, yawPidOutputs.value, speedPidOutputs.value);
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
