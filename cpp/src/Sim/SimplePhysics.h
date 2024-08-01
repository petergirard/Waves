//
// Created by Peter on 6/30/2024.
//

#ifndef WAVES_SIMPLEPHYSICS_H
#define WAVES_SIMPLEPHYSICS_H


#include "../Model/Navigation/PhysicalState.h"
#include "../Model/Maneuver/ManeuverControlsState.h"

class SimplePhysics {
public:
    [[nodiscard]] PhysicalState update(const PhysicalState &lastState,
                                       const ManeuverControlsState &controls,
                                       const double& dt) const;

private:
    const double MAX_SPEED = 3; // m/s
    const double MAX_TURN_RATE = 0.1745; // rads/s = 10 deg/s
    const double MAX_TURN_ACCEL = 0.0523599; // rads/s^2 = 3 deg/s^2
    const double BUOYANCY_VELOCITY = 0.05; // m/s
    const double MAX_FIN_ANGLE = 0.785398; // radians or 45 deg
    const double MAX_ACCELERATION = 1; // m/s^2

    [[nodiscard]] double boundRate(double rateIn, double lastRate, double maxAccel, double dt) const;
};


#endif //WAVES_SIMPLEPHYSICS_H
