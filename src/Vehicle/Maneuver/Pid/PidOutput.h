//
// Created by Peter on 6/13/2024.
//

#ifndef WAVES_PIDOUTPUT_H
#define WAVES_PIDOUTPUT_H

#include <chrono>

using TimePoint = std::chrono::time_point<std::chrono::system_clock,std::chrono::duration<double>>;

class PidOutput{
public:
    double value = 0; // output value of the PID loop
    double error = 0; // error that went into the PID loop
    double integral = 0; // integral that came out of PID loop
    TimePoint time{}; // Initialized to epoch. Time that PID loop was run.

    PidOutput() = default;
    PidOutput(double value_, double error_, double integral_, TimePoint t)
        : value(value_), error(error_), integral(integral_), time(t) {}
};

#endif //WAVES_PIDOUTPUT_H
