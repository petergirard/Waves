//
// Created by Peter on 6/4/2024.
//

#ifndef WAVES_MANEUVERCONTROLLER_H
#define WAVES_MANEUVERCONTROLLER_H


#include "../../Model/Maneuver/ManeuverControlsState.h"
#include "../../Model/Mission/Waypoint.h"
#include "../../Model/Maneuver/PhysicalState.h"
#include "../../Model/Maneuver/ManeuverGoalsState.h"
#include "ManeuverSettings.h"
#include "Pid/PidOutput.h"
#include "../../Model/Mission/MissionState.h"
#include <chrono>

using TimePoint = std::chrono::time_point<std::chrono::system_clock,std::chrono::duration<double>>;

class ManeuverController {
public:
    bool isStopped = true;
    ManeuverControlsState controls = ManeuverControlsState();
    ManeuverGoalsState maneuverGoalState = ManeuverGoalsState();
    void updateControls(const PhysicalState& physicalState,
                        const MissionState& missionState,
                        const TimePoint& currentTime);
    void stop();
    ManeuverController() = default;

private:
    static ManeuverGoalsState calculateManeuverState(const MissionState& missionState, PhysicalState physicalState);
    ManeuverSettings settings = ManeuverSettings(); // hardcoded to defaults for now.
    PhysicalState lastState = PhysicalState();
    TimePoint lastUpdateTime{};

    PidOutput depthPidOutputs = PidOutput();
    PidOutput pitchPidOutputs = PidOutput();
    PidOutput yawPidOutputs = PidOutput();
    PidOutput speedPidOutputs = PidOutput();
};


#endif //WAVES_MANEUVERCONTROLLER_H
