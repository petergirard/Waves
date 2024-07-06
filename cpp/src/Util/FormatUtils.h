//
// Created by Peter on 7/5/2024.
//

#ifndef WAVES_FORMATUTILS_H
#define WAVES_FORMATUTILS_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <cmath>
#include "../Model/Base/TimePoint.h"

class FormatUtils{
public:
    static::std::string doubleToString(double value, int precision) {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(precision) << value;
        return oss.str();
    }

    static std::string formatDate(TimePoint timePoint){
        return formatDate(timePoint.time_since_epoch().count());
    }

    static std::string formatDate(double epochSeconds) {
        auto time = static_cast<std::time_t>(epochSeconds);
        std::tm* timeInfo = std::localtime(&time);

        std::ostringstream oss;
        oss << std::setfill('0')
            << std::setw(2) << timeInfo->tm_mon + 1 << '/'
            << std::setw(2) << timeInfo->tm_mday << '/'
            << std::setw(4) << timeInfo->tm_year + 1900;

        return oss.str();
    }

    static std::string formatTime(TimePoint timePoint, bool localTime = false){
        return formatTime(timePoint.time_since_epoch().count(), localTime);
    }

    static std::string formatTime(double epochSeconds, bool localTime = false) {
        // Separate whole seconds and fractional part
        double intPart;
        double fractPart = std::modf(epochSeconds, &intPart);

        auto time = static_cast<std::time_t>(intPart);
        std::tm* timeInfo;
        if (localTime){
            timeInfo = std::localtime(&time);
        }
        else{
            timeInfo = std::gmtime(&time);
        }

        std::ostringstream oss;
        oss << std::setfill('0')
            << std::setw(2) << timeInfo->tm_hour << ':'
            << std::setw(2) << timeInfo->tm_min << ':'
            << std::setw(2) << timeInfo->tm_sec << '.'
            << std::setw(4) << static_cast<int>(fractPart * 10000);

        return oss.str();
    }
};


#endif //WAVES_FORMATUTILS_H
