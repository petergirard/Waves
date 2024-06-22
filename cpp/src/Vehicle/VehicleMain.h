//
// Created by Peter on 6/14/2024.
//

#ifndef WAVES_VEHICLEMAIN_H
#define WAVES_VEHICLEMAIN_H


#include "../Model/Maneuver/ManeuverState.h"
#include "../Model/Maneuver/ManeuverControls.h"
#include "../Model/Mission/NavigationStatus.h"
#include "Maneuver/ManeuverController.h"
#include "Mission/MissionController.h"


class VehicleMain {
public:
    VehicleMain() = default;

    [[nodiscard]] MissionStatus getMissionStatus() const;
    [[nodiscard]] NavigationStatus getNavigationStatus() const;
    [[nodiscard]] ManeuverControls getManeuverControls() const;

    void update(const ManeuverState& newState, const TimePoint& currentTime);
    void runMission(const Mission& mission);
    void stop();

private:
    ManeuverController maneuverController = ManeuverController();
    MissionController missionController = MissionController();
};


#endif //WAVES_VEHICLEMAIN_H
