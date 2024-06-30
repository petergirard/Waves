//
// Created by Peter on 6/28/2024.
//

#ifndef WAVES_WAVESSTATUSMESSAGE_H
#define WAVES_WAVESSTATUSMESSAGE_H

#include "../Model/Maneuver/ManeuverControls.h"
#include "../Model/Maneuver/ManeuverState.h"
#include "../Model/Mission/MissionStatus.h"
#include "../Model/Mission/NavigationStatus.h"
#include "../Model/Base/TimePoint.h"

class WavesStatusMessage{
public:
    ManeuverControls maneuverControls;
    ManeuverState maneuverState;
    MissionStatus missionStatus;
    NavigationStatus navigationStatus;
    TimePoint timePoint;
    double runTimeSeconds;

    WavesStatusMessage(ManeuverControls maneuverControls_,
                       ManeuverState maneuverState_,
                       MissionStatus missionStatus_,
                       NavigationStatus navigationStatus_,
                       TimePoint timePoint_,
                       double runTimeSeconds_)
                       : maneuverControls(maneuverControls_),
                       maneuverState(maneuverState_),
                       missionStatus(missionStatus_),
                       navigationStatus(navigationStatus_),
                       timePoint(timePoint_),
                       runTimeSeconds(runTimeSeconds_)
                       {}
};

#endif //WAVES_WAVESSTATUSMESSAGE_H
