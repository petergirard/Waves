//
// Created by Peter on 6/14/2024.
//

#ifndef WAVES_MISSIONSTATUS_H
#define WAVES_MISSIONSTATUS_H

#include "Mission.h"

enum MissionState{
    None,
    Running,
    Finished
};

class MissionStatus{
public:
    MissionState state = MissionState::None;
    Mission activeMission = Mission();
    Waypoint activeWaypoint = Waypoint();
    int activeWaypointIndex = 0;

    MissionStatus() = default;
    MissionStatus(const MissionStatus& other) = default;
    MissionStatus(MissionState state_, const Mission& activeMission_, const Waypoint& activeWaypoint_, int activeWaypointIndex_)
        : state(state_),
          activeMission(activeMission_),
          activeWaypoint(activeWaypoint_),
          activeWaypointIndex(activeWaypointIndex_) {}

    [[nodiscard]] MissionStatus progressWaypoint() const{
        int newWpIndex = activeWaypointIndex + 1;
        if (newWpIndex == activeMission.waypoints.size()){
            return {MissionState::Finished, activeMission, Waypoint(), 0};
        }
        return {MissionState::Running, activeMission, activeMission.waypoints[newWpIndex], newWpIndex};
    }
};

#endif //WAVES_MISSIONSTATUS_H
