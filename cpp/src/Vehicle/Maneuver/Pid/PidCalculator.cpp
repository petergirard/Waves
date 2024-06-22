//
// Created by Peter on 6/13/2024.
//

#include "PidCalculator.h"

PidOutput PidCalculator::calculate(const double& error, const TimePoint& timeNow, const PidOutput& lastOutput, const PidSettings& settings) {

    if (lastOutput.time.time_since_epoch().count() ==  0){
        // uninitialized
        double output = settings.kp * error;
        return {error, 0, output, timeNow};
    }

    auto start = std::chrono::system_clock::now();
    auto dt = (timeNow - lastOutput.time).count();

    auto integral = lastOutput.integral + error * dt;
    auto derivative = (error - lastOutput.error) / dt;

    auto output = settings.kp * error + settings.ki * integral + settings.kd * derivative;

    return {error, integral, output, timeNow};
}
