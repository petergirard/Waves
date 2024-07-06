//
// Created by Peter on 6/14/2024.
//

#ifndef WAVES_PHYSICALSTATE_H
#define WAVES_PHYSICALSTATE_H

#include "../Base/Point3D.h"
#include "../Base/Orientation.h"


class PhysicalState{
public:
    Point3D position = Point3D(); // meters.
    Vector3D velocityWorldFrame = Vector3D(); // meters / sec.
    Vector3D accelerationWorldFrame = Vector3D(); // meters / sec^2.
    Vector3D velocityVehicleFrame = Vector3D(); // meters / sec.
    Vector3D accelerationVehicleFrame = Vector3D(); // meters / sec^2
    Orientation attitude = Orientation(); // degrees.
    Orientation attitudeVelocity = Orientation(); // degrees / sec
    Orientation attitudeAcceleration = Orientation(); // degrees / sec^2

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
