//
// Created by Peter on 6/4/2024.
//

#ifndef WAVES_PHYSICS_H
#define WAVES_PHYSICS_H


#include "../Model/Navigation/PhysicalState.h"
#include "../Model/Maneuver/ManeuverControlsState.h"
#include "../Model/Base/TimePoint.h"
#include <cmath>

class Physics {
public:
    [[nodiscard]] PhysicalState update(const PhysicalState &lastState,
                                       const ManeuverControlsState &controls,
                                       const double& dt) const;

private:
    // CONSTANTS

    // Pilot Parameters
    const double VEHICLE_RADIUS = 0.10; // m
    const double VEHICLE_LENGTH = 2.0; // m
    const double VEHICLE_DISPLACEMENT = M_PI * VEHICLE_RADIUS * VEHICLE_RADIUS * VEHICLE_LENGTH; // m^3. Equation for volume of cylinder. Super rough.
    const double WATER_DENSITY = 1000.0; // kg/m^3 (approx density of water)
    const double DISPLACED_WATER_MASS = VEHICLE_DISPLACEMENT * WATER_DENSITY; // kg
    const double VEHICLE_MASS = DISPLACED_WATER_MASS * 0.98; // 2% buoyant.
    const double VEHICLE_AREA_YZ_PLANE = M_PI * VEHICLE_RADIUS * VEHICLE_RADIUS; // pi r^2;
    const double VEHICLE_AREA_XY_PLANE = M_PI * VEHICLE_RADIUS * 2.0 * VEHICLE_LENGTH;

    // Forces
    const double GRAVITY = 9.81; // m/s^2
    const double BUOYANCY_FORCE = -1.0 * (VEHICLE_DISPLACEMENT * WATER_DENSITY * GRAVITY); // positive downward.
    const double WEIGHT = VEHICLE_MASS * GRAVITY;
    const double NET_BUOYANCY = WEIGHT + BUOYANCY_FORCE;
    const double MOMENT_OF_INERTIA = 100; // (1.0 / 12.0) * VEHICLE_MASS * (3 * VEHICLE_RADIUS * VEHICLE_RADIUS + VEHICLE_LENGTH * VEHICLE_LENGTH); // moment of inertia along long axis of cylinder equation
    const double ADDED_MASS_PERCENTAGE = 0.2; // Percentage of mass added to vehicle mass. Need more exact value.

    // Coefficients and Scalars
    const double DRAG_COEFF_X = 0.2;
    const double DRAG_COEFF_Y = 0.8;
    const double DRAG_COEFF_Z = 0.8;
    const double THRUST_MAX = 100.0;    // N

    // Control Effectiveness
    const double ELEVATOR_EFFECTIVENESS = 0.05; // Effectiveness coefficient for the elevator
    const double RUDDER_EFFECTIVENESS = 0.05; // Effectiveness coefficient for the rudder
    const double PITCH_DAMPING_COEFF = 0.1; // Damping coefficient for pitch
    const double YAW_DAMPING_COEFF = 0.1; // Damping coefficient for yaw

    [[nodiscard]] double calculateDrag(double speed, double dragCoeff, double area) const;
};


#endif //WAVES_PHYSICS_H
