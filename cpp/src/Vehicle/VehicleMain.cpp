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

BatteryState VehicleMain::getBatteryState() const {
    return batteryManager.batteryState;
}

void VehicleMain::update(const PhysicalState &newState, const double& dt) {
    missionController.update(newState);
    if (getMissionState().activeMissionState == ActiveMissionState::Finished){
        maneuverController.stop();
        return;
    }

    maneuverController.updateControls(newState, getMissionState(), dt);
    batteryManager.update(getManeuverControlsState(), dt);
}

void VehicleMain::runMission(const std::string& missionName) {
    auto mission = missionRepo.getMission(missionName);
    if (mission.has_value())
        missionController.runMission(mission.value());
    else
        throw std::runtime_error("Mission not found in repository.");
}

void VehicleMain::loadAndRunMission(const Mission &mission) {
    missionRepo.loadMission(mission);
    missionController.runMission(mission);
}

void VehicleMain::stop() {
    maneuverController.stop();
    missionController.stop();
}




