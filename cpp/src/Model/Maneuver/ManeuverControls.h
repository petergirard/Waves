//
// Created by Peter on 6/4/2024.
//

#ifndef WAVES_MANEUVERCONTROLS_H
#define WAVES_MANEUVERCONTROLS_H

#include "../../Util/GenericUtils.h"

struct ManeuverControls{
public:
    double pitchGoal = 0;
    double elevator = 0; // -1 to 1. Affects pitch. Positive trailing edge down.
    double rudder = 0; // -1 to 1. Affects yaw. Positive trailing edge to port.
    double throttle = 0; // 0 t 1.

    ManeuverControls() = default;
    ManeuverControls(double pitchGoal, double elevator_, double rudder_, double throttle_) : pitchGoal(pitchGoal) {
        elevator = GenericUtils::boundNumber(elevator_, -1 ,1);
        rudder = GenericUtils::boundNumber(rudder_, -1 ,1);
        throttle = GenericUtils::boundNumber(throttle_, 0, 1);
    }
};

#endif //WAVES_MANEUVERCONTROLS_H
