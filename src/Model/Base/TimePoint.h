//
// Created by Peter on 6/14/2024.
//

#ifndef WAVES_TIMEPOINT_H
#define WAVES_TIMEPOINT_H

#include <chrono>

using TimePoint = std::chrono::time_point<std::chrono::system_clock,std::chrono::duration<double>>;

#endif //WAVES_TIMEPOINT_H
