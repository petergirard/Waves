//
// Created by Peter on 6/14/2024.
//

#ifndef WAVES_PILOT_H
#define WAVES_PILOT_H

#include "../Model/Navigation/PhysicalState.h"
#include "../Model/Maneuver/ManeuverControlsState.h"
#include "../Model/Maneuver/ManeuverGoalsState.h"
#include "Maneuver/PidController.h"
#include "Mission/MissionEngine.h"
#include "Mission/MissionRepo.h"
#include "Fuel/BatteryManager.h"


class Pilot {
public:
    Pilot() = default;

    MissionRepo missionRepo;
    BatteryManager fuelManager;

    [[nodiscard]] MissionExecutionState getMissionState() const;
    [[nodiscard]] std::optional<ManeuverGoalsState> getManeuverGoalsState() const;
    [[nodiscard]] ManeuverControlsState getManeuverControlsState() const;
    [[nodiscard]] BatteryState getBatteryState() const;

    void loadMission(Mission&& mission);
    void setActiveMission(const std::string& missionName);
    void addCurrentManeuver(std::unique_ptr<ManeuverBase> maneuver);
    void stop();

    void update(const PhysicalState& newState, const TimePoint& time, const double& dt);

private:
    ManeuverEngine _maneuverEngine{};
    MissionEngine _missionEngine{};
    BatteryManager _batteryManager{};

    void setCurrentWaypointToActiveManeuver();
    [[nodiscard]] static DriveToManeuver convertWaypointToManeuver(const Waypoint& wp, const std::optional<Waypoint>& previousWp) ;
};


#endif //WAVES_PILOT_H
