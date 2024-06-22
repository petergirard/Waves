//
// Created by Peter on 6/4/2024.
//

#include <chrono>
#include "Physics.h"
#include "../Util/FrameTransformations.h"

ManeuverState Physics::update(const ManeuverState &lastState,
                               const ManeuverControls &controls,
                               const double &dt) const {

    // Compute forces
    double speed = lastState.velocityWorldFrame.magnitude;
    double drag = 0.5 * WATER_DENSITY * speed * speed * DRAG_COEFF;
    double thrust = controls.throttle * THRUST_MAX;

    // Compute force components
    double dragX = drag * std::cos(lastState.attitude.pitch) * std::cos(lastState.attitude.yaw);
    double dragY = drag * std::cos(lastState.attitude.pitch) * std::sin(lastState.attitude.yaw);
    double dragZ = drag * std::sin(lastState.attitude.pitch);
    double thrustX = thrust * std::cos(lastState.attitude.pitch) * std::cos(lastState.attitude.yaw);
    double thrustY = thrust * std::cos(lastState.attitude.pitch) * std::sin(lastState.attitude.yaw);
    double thrustZ = thrust * std::sin(lastState.attitude.pitch);

    // Compute net forces
    double forceX = thrustX - dragX;
    double forceY = thrustY - dragY;
    double forceZ = thrustZ - dragZ; // + NET_BUOYANCY;
    Vector3D force = {forceX, forceY, forceZ};

    // Update linear motion
    Vector3D accelerationWorldFrame = force / MASS;
    Vector3D velocityWorldFrame = lastState.velocityWorldFrame + (accelerationWorldFrame * dt);
    Point3D position = lastState.position + velocityWorldFrame * dt;
    if (position.z < 0){ // Bound to surface.
        position = {position.x, position.y, 0};
        velocityWorldFrame = {velocityWorldFrame.x, velocityWorldFrame.y, 0};
        accelerationWorldFrame = {accelerationWorldFrame.x, accelerationWorldFrame.y, 0};
    }
    Vector3D accelerationVehicleFrame = FrameTransformations::worldToVehicle(accelerationWorldFrame, lastState.attitude);
    Vector3D velocityVehicleFrame = FrameTransformations::worldToVehicle(velocityWorldFrame, lastState.attitude);


    // Update angular motion
    double pitch_moment = controls.elevator * ELEVATOR_EFFECTIVENESS * thrust
                          - PITCH_DAMPING_COEFF * lastState.attitudeVelocity.pitch;
    double yaw_moment = controls.rudder * RUDDER_EFFECTIVENESS * thrust
                        - YAW_DAMPING_COEFF * lastState.attitudeVelocity.yaw;
    double pitch_acceleration = pitch_moment / MOMENT_OF_INERTIA;
    double yaw_acceleration = yaw_moment / MOMENT_OF_INERTIA;
    double pitch_rate = lastState.attitudeVelocity.pitch + pitch_acceleration * dt;
    double yaw_rate = lastState.attitudeVelocity.yaw + yaw_acceleration * dt;
    double pitch = lastState.attitude.pitch + pitch_rate * dt;
    double yaw = lastState.attitude.yaw + yaw_rate * dt;

    Orientation attitude = {0, pitch, yaw};
    Orientation attitudeVelocity = {0, pitch_rate, yaw_rate};
    Orientation attitudeAcceleration = {0, pitch_acceleration, yaw_acceleration};

    return {position,
            velocityWorldFrame,
            accelerationWorldFrame,
            velocityVehicleFrame,
            accelerationVehicleFrame,
            attitude,
            attitudeVelocity,
            attitudeAcceleration};
}
