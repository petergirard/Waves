//
// Created by Peter on 6/4/2024.
//

#ifndef WAVES_MISSIONCONTROLLER_H
#define WAVES_MISSIONCONTROLLER_H


#include "../../Model/Mission/NavigationStatus.h"
#include "../../Model/Maneuver/ManeuverState.h"
#include "../../Model/Mission/Mission.h"
#include "../../Model/Mission/MissionStatus.h"

class MissionController {
public:
    bool isActiveMission = false;
    MissionStatus missionStatus = MissionStatus();
    NavigationStatus navigationStatus = NavigationStatus();

    void update(const ManeuverState& state);
    void runMission(const Mission& mission);
    void stop();
};


#endif //WAVES_MISSIONCONTROLLER_H
