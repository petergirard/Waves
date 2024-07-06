//
// Created by Peter on 6/28/2024.
//

#ifndef WAVES_WAVESSTATUSMESSAGE_H
#define WAVES_WAVESSTATUSMESSAGE_H

#include "../Model/Maneuver/ManeuverControlsState.h"
#include "../Model/Maneuver/PhysicalState.h"
#include "../Model/Mission/MissionState.h"
#include "../Model/Maneuver/ManeuverGoalsState.h"
#include "../Model/Base/TimePoint.h"

class WavesStatusMessage{
public:
    ManeuverControlsState maneuverControlsState;
    PhysicalState physicalState;
    MissionState missionState;
    ManeuverGoalsState maneuverGoalsState;
    TimePoint timePoint;
    double runTimeSeconds;

    WavesStatusMessage(ManeuverControlsState maneuverControls_,
                       PhysicalState physicalState_,
                       MissionState missionState_,
                       ManeuverGoalsState maneuverGoalsState_,
                       TimePoint timePoint_,
                       double runTimeSeconds_)
                       : maneuverControlsState(maneuverControls_),
                         physicalState(physicalState_),
                         missionState(missionState_),
                         maneuverGoalsState(maneuverGoalsState_),
                         timePoint(timePoint_),
                         runTimeSeconds(runTimeSeconds_)
                       {}
};

#endif //WAVES_WAVESSTATUSMESSAGE_H
