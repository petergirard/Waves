//
// Created by Peter on 6/14/2024.
//

#include "VehicleMain.h"

MissionStatus VehicleMain::getMissionStatus() const {
    return missionController.missionStatus;
}

NavigationStatus VehicleMain::getNavigationStatus() const {
    return missionController.navigationStatus;
}

ManeuverControls VehicleMain::getManeuverControls() const {
    return maneuverController.controls;
}

void VehicleMain::update(const ManeuverState &newState, const TimePoint &currentTime) {
    missionController.update(newState);
    if (getMissionStatus().state == MissionState::Finished){
        maneuverController.stop();
        return;
    }

    maneuverController.updateControls(newState, getNavigationStatus(), currentTime);
}

void VehicleMain::runMission(const Mission &mission) {
    missionController.runMission(mission);
}

void VehicleMain::stop() {
    maneuverController.stop();
    missionController.stop();
}


