//
// Created by Peter on 6/4/2024.
//

#ifndef WAVES_MISSIONENGINE_H
#define WAVES_MISSIONENGINE_H


#include "../../Model/Maneuver/ManeuverGoalsState.h"
#include "../../Model/Navigation/PhysicalState.h"
#include "../../Model/Mission/Mission.h"
#include "../../Model/Mission/MissionExecutionState.h"
#include "../Maneuver/ManeuverEngine.h"

class MissionEngine {
public:
    [[nodiscard]] bool isMissionActive() const;
    [[nodiscard]] MissionExecutionState getMissionState() const;
    void runMission(const Mission& mission);
    void progressWaypoint();
    void reset();

private:
    bool _isMissionActive = false;
    MissionExecutionState _missionState{};
};


#endif //WAVES_MISSIONENGINE_H
