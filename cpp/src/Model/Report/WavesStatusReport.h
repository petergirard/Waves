//
// Created by Peter on 6/28/2024.
//

#ifndef WAVES_WAVESSTATUSREPORT_H
#define WAVES_WAVESSTATUSREPORT_H

#include <optional>
#include <utility>
#include "../Maneuver/ManeuverControlsState.h"
#include "../Navigation/PhysicalState.h"
#include "../Mission/MissionExecutionState.h"
#include "../Maneuver/ManeuverGoalsState.h"
#include "../Base/TimePoint.h"
#include "../Misc/BatteryState.h"

class WavesStatusReport{
public:
    ManeuverControlsState maneuverControlsState{};
    PhysicalState physicalState{};
    std::optional<MissionExecutionState> missionExecutionState{};
    std::optional<ManeuverGoalsState> maneuverGoalsState{};
    BatteryState batteryState{};
    TimePoint timePoint{};
    double runTimeSeconds{};

    WavesStatusReport(ManeuverControlsState maneuverControls_,
                      PhysicalState physicalState_,
                      std::optional<MissionExecutionState> missionExecutionState_,
                      std::optional<ManeuverGoalsState> maneuverGoalsState_,
                      BatteryState batteryState_,
                      TimePoint timePoint_,
                      double runTimeSeconds_)
                       : maneuverControlsState(maneuverControls_),
                         physicalState(physicalState_),
                         missionExecutionState(std::move(missionExecutionState_)),
                         maneuverGoalsState(maneuverGoalsState_),
                         batteryState(batteryState_),
                         timePoint(timePoint_),
                         runTimeSeconds(runTimeSeconds_)
                       {}
};

#endif //WAVES_WAVESSTATUSREPORT_H
