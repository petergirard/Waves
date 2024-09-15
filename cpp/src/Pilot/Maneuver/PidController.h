//
// Created by Peter on 6/4/2024.
//

#ifndef WAVES_PIDCONTROLLER_H
#define WAVES_PIDCONTROLLER_H

#include "../../Model/Maneuver/ManeuverControlsState.h"
#include "../../Model/Mission/Waypoint.h"
#include "../../Model/Navigation/PhysicalState.h"
#include "../../Model/Maneuver/ManeuverGoalsState.h"
#include "../../Model/Mission/MissionExecutionState.h"
#include "../../Model/Maneuver/DriveToManeuver.h"
#include "../../Model/Maneuver/ParkManeuver.h"
#include "DriveSettings.h"
#include "PidOutput.h"
#include <chrono>
#include <variant>

class PidController {
public:
    [[nodiscard]] bool isStopped() const;
    [[nodiscard]] ManeuverControlsState getControlsState() const;
    [[nodiscard]] ManeuverGoalsState getManeuverGoalsState() const;

    void update(const DriveToManeuver& maneuver, const PhysicalState& physicalState, const double& dt);
    void stop();
    void reset();
    PidController() = default;

private:
    bool _isStopped = true;
    ManeuverControlsState _controlsState{};
    ManeuverGoalsState _maneuverGoalsState{};

    PidOutput _depthPidOutputs;
    PidOutput _pitchPidOutputs;
    PidOutput _yawPidOutputs;
    PidOutput _speedPidOutputs;

    ManeuverGoalsState calculateManeuverGoals(const DriveToManeuver& driveToManeuver, const PhysicalState& physicalState,
                                              const double& dt, const bool& updateIntegral);
    static PidOutput calculatePid(const double& error, const double& dt, const PidOutput& lastOutput,
                                  const PidSettings& pidSettings, const bool& updateIntegral);
    DriveSettings settings = DriveSettings(); // hardcoded to defaults for now.
};


#endif //WAVES_PIDCONTROLLER_H
