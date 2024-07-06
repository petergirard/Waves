//
// Created by Peter on 6/13/2024.
//

#ifndef WAVES_PIDSETTINGS_H
#define WAVES_PIDSETTINGS_H

class PidSettings{
public:
    double kp;
    double kd;
    double ki;

    PidSettings(double kp_, double kd_, double ki_) : kp(kp_), kd(kd_), ki(ki_) {}
};

#endif //WAVES_PIDSETTINGS_H
