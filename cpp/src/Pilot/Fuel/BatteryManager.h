//
// Created by Peter on 7/6/2024.
//

#ifndef WAVES_BATTERYMANAGER_H
#define WAVES_BATTERYMANAGER_H


#include "../../Model/Maneuver/ManeuverControlsState.h"
#include "../../Model/Misc/BatteryState.h"

// This class is temporary until a battery module is added to the simulator that feeds battery percentages through a serial connection.
class BatteryManager {
public:
    const double HOTEL_LOAD_WATTS = 50.0;
    const double RESERVE_WATT_HOURS = 2000.0;
    const double POWER_CURVE_WATTS = 100.0; // 100 watts at 100% throttle;

    BatteryManager() = default;

    BatteryState batteryState = {1, RESERVE_WATT_HOURS};

    void reset();
    void update(const ManeuverControlsState& maneuverControls, double dt);
};


#endif //WAVES_BATTERYMANAGER_H
