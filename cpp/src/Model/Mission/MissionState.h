//
// Created by Peter on 6/14/2024.
//

#ifndef WAVES_MISSIONSTATE_H
#define WAVES_MISSIONSTATE_H

#include "Mission.h"

enum ActiveMissionState{
    Unknown,
    Running,
    Finished
};

class MissionState{
public:
    ActiveMissionState activeMissionState = ActiveMissionState::Unknown;
    Mission activeMission = Mission();
    Waypoint activeWaypoint = Waypoint();
    int activeWaypointIndex = 0;
    double distanceToWaypoint = 0;

    MissionState() = default;
    MissionState(const MissionState& other) = default;
    MissionState(ActiveMissionState activeMissionState,
                 const Mission& activeMission_,
                 const Waypoint& activeWaypoint_,
                 int activeWaypointIndex_,
                 double distanceToWaypoint_)
        : activeMissionState(activeMissionState),
          activeMission(activeMission_),
          activeWaypoint(activeWaypoint_),
          activeWaypointIndex(activeWaypointIndex_),
          distanceToWaypoint(distanceToWaypoint_) {}
};

#endif //WAVES_MISSIONSTATE_H
