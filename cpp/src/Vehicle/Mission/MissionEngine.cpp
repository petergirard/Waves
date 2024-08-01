//
// Created by Peter on 6/4/2024.
//

#include "MissionEngine.h"

MissionExecutionState MissionEngine::getMissionState() const {
    return _missionState;
}

bool MissionEngine::isMissionActive() const {
    return _isMissionActive;
}

void MissionEngine::runMission(const Mission& mission) {
    _missionState = MissionExecutionState(ActiveMissionState::Running,
                                         mission,
                                         mission.waypoints[0],
                                         0);
    _isMissionActive = true;
}

void MissionEngine::reset() {
    _missionState = MissionExecutionState();
}

void MissionEngine::progressWaypoint() {
    int newWpIndex = _missionState.activeWaypointIndex + 1;
    if (newWpIndex == _missionState.activeMission.waypoints.size()){
        _missionState = MissionExecutionState(ActiveMissionState::Finished,
                                              _missionState.activeMission,
                                              Waypoint(),
                                              0);
    }

    auto activeWaypoint = _missionState.activeMission.waypoints[newWpIndex];

    _missionState = {ActiveMissionState::Running,
            _missionState.activeMission,
            activeWaypoint,
            newWpIndex};
}