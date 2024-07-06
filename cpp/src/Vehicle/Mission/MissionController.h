//
// Created by Peter on 6/4/2024.
//

#ifndef WAVES_MISSIONCONTROLLER_H
#define WAVES_MISSIONCONTROLLER_H


#include "../../Model/Maneuver/ManeuverGoalsState.h"
#include "../../Model/Maneuver/PhysicalState.h"
#include "../../Model/Mission/Mission.h"
#include "../../Model/Mission/MissionState.h"

class MissionController {
public:
    bool isActiveMission = false;
    MissionState missionState = MissionState();

    void update(const PhysicalState& physicalState);
    void runMission(const Mission& mission);
    void stop();

private:
    [[nodiscard]] static MissionState progressWaypoint(const MissionState& missionStatus, const PhysicalState& physicalState);
};


#endif //WAVES_MISSIONCONTROLLER_H
