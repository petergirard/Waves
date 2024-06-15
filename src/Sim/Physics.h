//
// Created by Peter on 6/4/2024.
//

#ifndef WAVES_PHYSICS_H
#define WAVES_PHYSICS_H


#include "../Model/Maneuver/ManeuverState.h"
#include "../Model/Maneuver/ManeuverControls.h"

using TimePoint = std::chrono::time_point<std::chrono::system_clock,std::chrono::duration<double>>;

class Physics {
public:
    [[nodiscard]] ManeuverState update(const ManeuverState &lastState,
                          const ManeuverControls &controls,
                          const double& dt) const;

private:
    // Constants
    const double GRAVITY = 9.81;         // m/s^2
    const double MASS = 1000.0;          // kg
    const double VEHICLE_DISPLACEMENT = 1.02; // m^3
    const double WATER_DENSITY = 1000.0; // kg/m^3 (approx density of water)
    const double BUOYANCY_FORCE = VEHICLE_DISPLACEMENT * WATER_DENSITY;
    const double DRAG_COEFF = 0.05;
    const double THRUST_MAX = 5000.0;    // N
    const double MOMENT_OF_INERTIA = 10000.0; // kg.m^2
};


#endif //WAVES_PHYSICS_H
