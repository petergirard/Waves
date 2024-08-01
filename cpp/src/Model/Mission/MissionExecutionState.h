//
// Created by Peter on 6/14/2024.
//

#ifndef WAVES_MISSIONEXECUTIONSTATE_H
#define WAVES_MISSIONEXECUTIONSTATE_H

#include "Mission.h"

enum ActiveMissionState{
    Unknown,
    Running,
    Finished
};

class MissionExecutionState{
public:
    ActiveMissionState activeMissionState = ActiveMissionState::Unknown;
    Mission activeMission{};
    Waypoint activeWaypoint{};
    int activeWaypointIndex = 0;

    MissionExecutionState() = default;
    MissionExecutionState(const MissionExecutionState& other) = default;
    MissionExecutionState(ActiveMissionState activeMissionState,
                          const Mission& activeMission_,
                          const Waypoint& activeWaypoint_,
                          int activeWaypointIndex_)
        : activeMissionState(activeMissionState),
          activeMission(activeMission_),
          activeWaypoint(activeWaypoint_),
          activeWaypointIndex(activeWaypointIndex_) {}
};

#endif //WAVES_MISSIONEXECUTIONSTATE_H
