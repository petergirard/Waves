//
// Created by Peter on 6/14/2024.
//

#ifndef WAVES_MANEUVERSTATE_H
#define WAVES_MANEUVERSTATE_H

#include "../Base/Point3D.h"
#include "../Base/TimePoint.h"
#include "../Base/Orientation.h"


class ManeuverState{
public:
    Point3D position = Point3D(); // meters.
    Vector3D velocityWorldFrame = Vector3D(); // meters / sec.
    Vector3D accelerationWorldFrame = Vector3D(); // meters / sec^2.
    Vector3D velocityVehicleFrame = Vector3D(); // meters / sec.
    Vector3D accelerationVehicleFrame = Vector3D(); // meters / sec^2
    Orientation attitude = Orientation(); // degrees.
    Orientation attitudeVelocity = Orientation(); // degrees / sec
    Orientation attitudeAcceleration = Orientation(); // degrees / sec^2

    ManeuverState() = default;
    ManeuverState(Point3D position_,
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

#endif //WAVES_MANEUVERSTATE_H
