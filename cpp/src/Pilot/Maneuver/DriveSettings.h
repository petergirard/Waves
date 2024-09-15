//
// Created by Peter on 6/13/2024.
//

#ifndef WAVES_DRIVESETTINGS_H
#define WAVES_DRIVESETTINGS_H

#include <chrono>
#include "PidSettings.h"


class DriveSettings{
public:
    PidSettings depthPid = PidSettings(0.1, 0.1, 0);
    PidSettings pitchPid = PidSettings(1, 0, 0);
    PidSettings yawPid = PidSettings(1, 0, 0);
    PidSettings speedPid = PidSettings(0, 0, 0.1);

    DriveSettings() = default;
};

#endif //WAVES_DRIVESETTINGS_H
