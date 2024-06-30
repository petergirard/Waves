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
    double depthGoal = missionStatus.activeWaypoint.depth;
    double speedGoal = missionStatus.activeWaypoint.speed;

    double yawError = yawGoal - state.attitude.yaw;
    double depthError = depthGoal - state.position.z;
    double speedError = speedGoal - state.velocityWorldFrame.to2D().magnitude;

    navigationStatus = {distanceToWaypoint,
                        yawGoal,
                        yawError,
                        depthGoal,
                        depthError,
                        speedGoal,
                        speedError};
}

void MissionController::runMission(const Mission& mission) {
    missionStatus = MissionStatus(MissionState::Running, mission, mission.waypoints[0], 0);
}

void MissionController::stop() {
    missionStatus = MissionStatus(MissionState::Unknown, Mission(), Waypoint(), 0);
    navigationStatus = NavigationStatus();
}
