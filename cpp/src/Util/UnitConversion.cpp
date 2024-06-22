//
// Created by Peter on 6/4/2024.
//

#include "UnitConversion.h"
#include "cmath"

double UnitConversion::toDegrees(double radians) {
    return radians * (180.0 / M_PI);
}

double UnitConversion::toRadians(double degrees) {
    return degrees * M_PI / 180;
}
