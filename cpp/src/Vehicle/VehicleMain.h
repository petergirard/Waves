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


class VehicleMain {
public:
    VehicleMain() = default;

    [[nodiscard]] MissionState getMissionState() const;
    [[nodiscard]] ManeuverGoalsState getManeuverGoalsState() const;
    [[nodiscard]] ManeuverControlsState getManeuverControlsState() const;

    void update(const PhysicalState& newState, const TimePoint& currentTime);
    void runMission(const Mission& mission);
    void stop();

private:
    ManeuverController maneuverController = ManeuverController();
    MissionController missionController = MissionController();
};


#endif //WAVES_VEHICLEMAIN_H
