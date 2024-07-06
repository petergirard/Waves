//
// Created by Peter on 7/6/2024.
//

#ifndef WAVES_BATTERYSTATE_H
#define WAVES_BATTERYSTATE_H

struct BatteryState{
public:
    double percentRemaining = 0;
    double wattHoursRemaining = 0;

    BatteryState() = default;
    BatteryState(double percent, double wattHours) : percentRemaining(percent), wattHoursRemaining(wattHours) {}
};
#endif //WAVES_BATTERYSTATE_H
