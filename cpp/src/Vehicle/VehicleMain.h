//
// Created by Peter on 6/14/2024.
//

#ifndef WAVES_VEHICLEMAIN_H
#define WAVES_VEHICLEMAIN_H


#include "../Model/Maneuver/PhysicalState.h"
#include "../Model/Maneuver/ManeuverControlsState.h"
#include "../Model/Maneuver/ManeuverGoalsState.h"
#include "Maneuver/ManeuverController.h"
#include "Mission/MissionController.h"
#include "Mission/MissionRepo.h"
#include "Fuel/BatteryManager.h"


class VehicleMain {
public:
    VehicleMain() = default;

    MissionRepo missionRepo;
    BatteryManager fuelManager;

    [[nodiscard]] MissionState getMissionState() const;
    [[nodiscard]] ManeuverGoalsState getManeuverGoalsState() const;
    [[nodiscard]] ManeuverControlsState getManeuverControlsState() const;
    [[nodiscard]] BatteryState getBatteryState() const;

    void runMission(const std::string& missionName);
    void loadAndRunMission(const Mission& mission);
    void update(const PhysicalState& newState, const double& dt);

    void stop();

private:
    ManeuverController maneuverController = ManeuverController();
    MissionController missionController = MissionController();
    BatteryManager batteryManager = BatteryManager();
};


#endif //WAVES_VEHICLEMAIN_H
