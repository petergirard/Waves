//
// Created by Peter on 6/28/2024.
//

#ifndef WAVES_WAVESSTATUSREPORT_H
#define WAVES_WAVESSTATUSREPORT_H

#include "../Maneuver/ManeuverControlsState.h"
#include "../Maneuver/PhysicalState.h"
#include "../Mission/MissionState.h"
#include "../Maneuver/ManeuverGoalsState.h"
#include "../Base/TimePoint.h"
#include "../Misc/BatteryState.h"

class WavesStatusReport{
public:
    ManeuverControlsState maneuverControlsState;
    PhysicalState physicalState;
    MissionState missionState;
    ManeuverGoalsState maneuverGoalsState;
    BatteryState batteryState;
    TimePoint timePoint;
    double runTimeSeconds;

    WavesStatusReport(ManeuverControlsState maneuverControls_,
                      PhysicalState physicalState_,
                      MissionState missionState_,
                      ManeuverGoalsState maneuverGoalsState_,
                      BatteryState batteryState_,
                      TimePoint timePoint_,
                      double runTimeSeconds_)
                       : maneuverControlsState(maneuverControls_),
                         physicalState(physicalState_),
                         missionState(missionState_),
                         maneuverGoalsState(maneuverGoalsState_),
                         batteryState(batteryState_),
                         timePoint(timePoint_),
                         runTimeSeconds(runTimeSeconds_)
                       {}
};

#endif //WAVES_WAVESSTATUSREPORT_H
