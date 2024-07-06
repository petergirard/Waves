//
// Created by Peter on 6/30/2024.
//

#include "SimplePhysics.h"
#include "../Util/MathUtils.h"
#include "../Util/FrameTransformations.h"

PhysicalState
SimplePhysics::update(const PhysicalState &lastState,
                      const ManeuverControlsState &controls,
                      const double &dt) const {

    // Speed
    double speedIn = controls.throttle * MAX_SPEED;
    double speedFinal = boundRate(speedIn, lastState.velocityVehicleFrame.x, MAX_ACCELERATION, dt);

    // Attitude
    double pitchRateIn = speedFinal > 0 ? controls.elevator * MAX_TURN_RATE : 0;
    double yawRateIn = speedFinal > 0 ? controls.rudder * MAX_TURN_RATE : 0;
    double pitchRateFinal = boundRate(pitchRateIn, lastState.attitudeVelocity.pitch, MAX_TURN_ACCEL, dt);
    double yawRateFinal = boundRate(yawRateIn, lastState.attitudeVelocity.yaw, MAX_TURN_ACCEL, dt);

    Orientation attitudeVelocity(0, pitchRateFinal, yawRateFinal);
    Orientation attitude = lastState.attitude + attitudeVelocity * dt;

    // Velocities
    Vector3D velocityVehicleFrame(speedFinal, 0, 0); // simple = no y or z speed.
    Vector3D velocityWorldFrame = FrameTransformations::vehicleToWorld(velocityVehicleFrame, attitude);

    // Position
    Point3D newPosition = lastState.position + velocityWorldFrame * dt;
    if (newPosition.z < 0){
        newPosition.z = 0;
        velocityWorldFrame.z = 0;
    }

    // Accelerations
    Vector3D accelerationVehicleFrame = (velocityVehicleFrame - lastState.velocityVehicleFrame) / dt;
    Vector3D accelerationWorldFrame = (velocityWorldFrame - lastState.velocityWorldFrame) / dt;
    Orientation attitudeAcceleration = (attitudeVelocity - lastState.attitudeVelocity) / dt;



    return {newPosition,
            velocityWorldFrame,
            accelerationWorldFrame,
            velocityVehicleFrame,
            accelerationVehicleFrame,
            attitude,
            attitudeVelocity,
            attitudeAcceleration};
}

double SimplePhysics::boundRate(double rateIn, double lastRate, double maxAccel, double dt) const {
    double rateDelta = rateIn - lastRate;
    double maxRateDelta = maxAccel * dt;
    return std::abs(rateDelta) < maxRateDelta
                        ? rateIn
                        : lastRate + (MathUtils::sign(rateDelta) * maxRateDelta);
}


