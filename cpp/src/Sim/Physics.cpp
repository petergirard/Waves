//
// Created by Peter on 6/4/2024.
//

#include <chrono>
#include "Physics.h"
#include "../Util/FrameTransformations.h"

PhysicalState Physics::update(const PhysicalState &lastState,
                              const ManeuverControlsState &controls,
                              const double &dt) const {

    // Compute forces
    double dragXVehicle = calculateDrag(lastState.velocityVehicleFrame.x, DRAG_COEFF_X, VEHICLE_AREA_YZ_PLANE);
    double dragYVehicle = calculateDrag(lastState.velocityVehicleFrame.y, DRAG_COEFF_Y, VEHICLE_AREA_XY_PLANE);
    double dragZVehicle = calculateDrag(lastState.velocityVehicleFrame.z, DRAG_COEFF_Z, VEHICLE_AREA_XY_PLANE);
    Vector3D dragVehicleFrame(dragXVehicle, dragYVehicle, dragZVehicle);
    Vector3D thrustVehicleFrame(controls.throttle * THRUST_MAX, 0, 0);
    Vector3D forceVehicleFrame = thrustVehicleFrame + dragVehicleFrame;

    // Limit force in fore-aft to only go forward
//    if (forceVehicleFrame.x < 0)
//        forceVehicleFrame.x = 0;

    // Transform to world frame.
    Vector3D forceWorldFrame = FrameTransformations::vehicleToWorld(forceVehicleFrame, lastState.attitude);
    forceWorldFrame.z += NET_BUOYANCY;

    // Update linear motion
    Vector3D accelerationWorldFrame = forceWorldFrame / (VEHICLE_MASS + VEHICLE_MASS * ADDED_MASS_PERCENTAGE);
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
    double pitch_moment = controls.elevator * ELEVATOR_EFFECTIVENESS * thrustVehicleFrame.x
                          - PITCH_DAMPING_COEFF * lastState.attitudeVelocity.pitch;
    double yaw_moment = controls.rudder * RUDDER_EFFECTIVENESS * thrustVehicleFrame.x
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

double Physics::calculateDrag(double speed, double dragCoeff, double area) const {
    double speedAbs = std::abs(speed);
    double dragForce = 0.5 * WATER_DENSITY * speedAbs * speedAbs * dragCoeff * area;
    return (speed > 0 ? -dragForce : dragForce);
}
