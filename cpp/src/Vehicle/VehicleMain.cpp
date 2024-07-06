//
// Created by Peter on 6/14/2024.
//

#include "VehicleMain.h"

MissionState VehicleMain::getMissionState() const {
    return missionController.missionState;
}

ManeuverGoalsState VehicleMain::getManeuverGoalsState() const {
    return maneuverController.maneuverGoalState;
}

ManeuverControlsState VehicleMain::getManeuverControlsState() const {
    return maneuverController.controls;
}

void VehicleMain::update(const PhysicalState &newState, const TimePoint &currentTime) {
    missionController.update(newState);
    if (getMissionState().activeMissionState == ActiveMissionState::Finished){
        maneuverController.stop();
        return;
    }

    maneuverController.updateControls(newState, getMissionState(), currentTime);
}

void VehicleMain::runMission(const Mission &mission) {
    missionController.runMission(mission);
}

void VehicleMain::stop() {
    maneuverController.stop();
    missionController.stop();
}


