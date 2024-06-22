//
// Created by Peter on 6/13/2024.
//

#ifndef WAVES_PIDCALCULATOR_H
#define WAVES_PIDCALCULATOR_H


#include <chrono>
#include "PidOutput.h"
#include "PidSettings.h"

using TimePoint = std::chrono::time_point<std::chrono::system_clock,std::chrono::duration<double>>;


class PidCalculator {
public:
    static PidOutput calculate(const double& error, const TimePoint& timeNow, const PidOutput& lastOutput, const PidSettings& settings);
};


#endif //WAVES_PIDCALCULATOR_H
