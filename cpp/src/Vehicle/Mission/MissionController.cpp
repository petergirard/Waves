//
// Created by Peter on 6/4/2024.
//

#include "MissionController.h"

void MissionController::update(const ManeuverState& state) {

    double distanceToWaypoint = state.position.to2D().distanceTo(missionStatus.activeWaypoint.position);

    if (distanceToWaypoint < missionStatus.activeWaypoint.successRadius){
        missionStatus = missionStatus.progressWaypoint();
        if (missionStatus.state == MissionState::Finished){
            navigationStatus = NavigationStatus();
        }
        else{
            update(state);
        }
    }

    double yawGoal = state.position.to2D().angleTo(state.position.to2D());
    double yawError = yawGoal - state.attitude.yaw;
    double depthError = missionStatus.activeWaypoint.depth - state.position.z;
    double speedError = missionStatus.activeWaypoint.speed - state.velocityWorldFrame.to2D().magnitude;

    navigationStatus = {distanceToWaypoint, yawError, depthError, speedError};
}

void MissionController::runMission(const Mission& mission) {
    missionStatus = MissionStatus(MissionState::Running, mission, mission.waypoints[0], 0);
}

void MissionController::stop() {
    missionStatus = MissionStatus(MissionState::None, Mission(), Waypoint(), 0);
    navigationStatus = NavigationStatus();
}
