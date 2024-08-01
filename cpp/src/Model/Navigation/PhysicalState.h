//
// Created by Peter on 6/14/2024.
//

#ifndef WAVES_PHYSICALSTATE_H
#define WAVES_PHYSICALSTATE_H

#include "../Base/Point3D.h"
#include "../Base/Orientation.h"


class PhysicalState{
public:
    Point3D position{}; // meters.
    Vector3D velocityWorldFrame{}; // meters / sec.
    Vector3D accelerationWorldFrame{}; // meters / sec^2.
    Vector3D velocityVehicleFrame{}; // meters / sec.
    Vector3D accelerationVehicleFrame{}; // meters / sec^2
    Orientation attitude{}; // degrees.
    Orientation attitudeVelocity{}; // degrees / sec
    Orientation attitudeAcceleration{}; // degrees / sec^2

    PhysicalState() = default;
    PhysicalState(Point3D position_,
                  Vector3D velocityWorldFrame_,
                  Vector3D accelerationWorldFrame_,
                  Vector3D velocityVehicleFrame_,
                  Vector3D accelerationVehicleFrame_,
                  Orientation attitude_,
                  Orientation attitudeVelocity_,
                  Orientation attitudeAcceleration_)
                  : position(position_),
                    velocityWorldFrame(velocityWorldFrame_),
                    accelerationWorldFrame(accelerationWorldFrame_),
                    velocityVehicleFrame(velocityVehicleFrame_),
                    accelerationVehicleFrame(accelerationVehicleFrame_),
                    attitude(attitude_),
                    attitudeVelocity(attitudeVelocity_),
                    attitudeAcceleration(attitudeAcceleration_) {}
};

#endif //WAVES_PHYSICALSTATE_H
