//
// Created by Peter on 6/13/2024.
//

#ifndef WAVES_MANEUVERSETTINGS_H
#define WAVES_MANEUVERSETTINGS_H

#include <chrono>
#include "Pid/PidSettings.h"


class ManeuverSettings{
public:
    PidSettings pitchPid = PidSettings(1, 0, 0.01);
    PidSettings yawPid = PidSettings(1, 0, 0.01);
    PidSettings speedPid = PidSettings(1, 0, 0.01);

    ManeuverSettings() = default;
};

#endif //WAVES_MANEUVERSETTINGS_H
