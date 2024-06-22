//
// Created by Peter on 6/4/2024.
//

#ifndef WAVES_MANEUVERCONTROLLER_H
#define WAVES_MANEUVERCONTROLLER_H


#include "../../Model/Maneuver/ManeuverControls.h"
#include "../../Model/Mission/Waypoint.h"
#include "../../Model/Maneuver/ManeuverState.h"
#include "../../Model/Mission/NavigationStatus.h"
#include "ManeuverSettings.h"
#include "Pid/PidOutput.h"
#include <chrono>

using TimePoint = std::chrono::time_point<std::chrono::system_clock,std::chrono::duration<double>>;

class ManeuverController {
public:
    bool isStopped = true;
    ManeuverControls controls = ManeuverControls();
    void updateControls(const ManeuverState& maneuverState,
                        const NavigationStatus& missionStatus,
                        const TimePoint& currentTime);
    void stop();
    ManeuverController() = default;

private:
    ManeuverSettings settings = ManeuverSettings(); // hardcoded to defaults for now.
    ManeuverState lastState = ManeuverState();
    TimePoint lastUpdateTime{};

    PidOutput depthPidOutputs = PidOutput();
    PidOutput pitchPidOutputs = PidOutput();
    PidOutput yawPidOutputs = PidOutput();
    PidOutput speedPidOutputs = PidOutput();
};


#endif //WAVES_MANEUVERCONTROLLER_H
