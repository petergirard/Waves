//
// Created by Peter on 7/6/2024.
//

#include "BatteryManager.h"

void BatteryManager::reset() {
    batteryState = {1, RESERVE_WATT_HOURS};
}

void BatteryManager::update(const ManeuverControlsState &maneuverControls, double dt) {

    // Calculate consumption
    double hotelWattSeconds = HOTEL_LOAD_WATTS * dt;
    double throttleWattSeconds = maneuverControls.throttle * POWER_CURVE_WATTS * dt;

    double totalWattSecondsUsed = hotelWattSeconds + throttleWattSeconds;
    double totalWattHoursUsed = totalWattSecondsUsed / 3600.0;
    double percentUsed = totalWattHoursUsed / RESERVE_WATT_HOURS;

    // Update properties
    batteryState.wattHoursRemaining -= totalWattHoursUsed;
    batteryState.percentRemaining -= percentUsed;
}



