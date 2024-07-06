//
// Created by Peter on 6/4/2024.
//

#include "MissionController.h"

void MissionController::update(const PhysicalState& physicalState) {

    double distanceToWaypoint = physicalState.position.to2D().distanceTo(missionState.activeWaypoint.position);

    if (distanceToWaypoint > missionState.activeWaypoint.successRadius)
        missionState.distanceToWaypoint = distanceToWaypoint;
    else{
        missionState = progressWaypoint(missionState, physicalState);
    }
}

void MissionController::runMission(const Mission& mission) {
    missionState = MissionState(ActiveMissionState::Running,
                                mission,
                                mission.waypoints[0],
                                0,
                                0);
}

void MissionController::stop() {
    missionState = MissionState();
}

MissionState MissionController::progressWaypoint(const MissionState& missionState, const PhysicalState& physicalState) {
    int newWpIndex = missionState.activeWaypointIndex + 1;
    if (newWpIndex == missionState.activeMission.waypoints.size()){
        return {ActiveMissionState::Finished, missionState.activeMission, Waypoint(), 0, 0};
    }

    auto activeWaypoint = missionState.activeMission.waypoints[newWpIndex];
    auto distanceToWaypoint = physicalState.position.to2D().distanceTo(activeWaypoint.position);

    return {ActiveMissionState::Running,
            missionState.activeMission,
            activeWaypoint,
            newWpIndex,
            distanceToWaypoint};
}