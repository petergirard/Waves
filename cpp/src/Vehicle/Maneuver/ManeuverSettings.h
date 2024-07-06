//
// Created by Peter on 6/13/2024.
//

#ifndef WAVES_MANEUVERSETTINGS_H
#define WAVES_MANEUVERSETTINGS_H

#include <chrono>
#include "PidSettings.h"


class ManeuverSettings{
public:
    PidSettings depthPid = PidSettings(0.1, 0.1, 0);
    PidSettings pitchPid = PidSettings(1, 0, 0);
    PidSettings yawPid = PidSettings(1, 0, 0);
    PidSettings speedPid = PidSettings(0, 0, 0.1);

    ManeuverSettings() = default;
};

#endif //WAVES_MANEUVERSETTINGS_H
