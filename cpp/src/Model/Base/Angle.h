//
// Created by Peter on 6/15/2024.
//

#ifndef WAVES_ANGLE_H
#define WAVES_ANGLE_H

#include "../../Util/UnitConversion.h"

class Angle{
public:
    double degrees = 0;
    double radians = 0;
    Angle() = default;

    bool operator==(const Angle& a) const{
        return degrees == a.degrees;
    }

    Angle operator+(const Angle& a) const{
        return fromDegrees(degrees + a.degrees);
    }
    Angle operator-(const Angle& a) const{
        return fromDegrees(degrees - a.degrees);
    }

    static Angle fromDegrees(double degrees){
        return {degrees, UnitConversion::toRadians(degrees)};
    };
    static Angle fromRadians(double radians){
        return {UnitConversion::toDegrees(radians), radians};
    }

private:
    Angle(double degrees_, double radians_) : degrees(degrees_), radians(radians_) {}
};

#endif //WAVES_ANGLE_H
