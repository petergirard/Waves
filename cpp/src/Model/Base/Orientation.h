//
// Created by Peter on 6/14/2024.
//

#ifndef WAVES_ORIENTATION_H
#define WAVES_ORIENTATION_H

#include <nlohmann/json.hpp>

struct Orientation{
public:
    double roll = 0;
    double pitch = 0;
    double yaw = 0;

    Orientation() = default;
    Orientation(double r, double p, double y) : roll(r), pitch(p), yaw(y) {}

    Orientation operator+(const Orientation& v) const{
        return {roll + v.roll, pitch + v.pitch, yaw + v.yaw};
    }
    Orientation operator-(const Orientation& v) const{
        return {roll - v.roll, pitch - v.pitch, yaw - v.yaw};
    }
    Orientation operator*(double scalar) const{
        return {roll * scalar, pitch * scalar, yaw * scalar};
    }
    Orientation operator/(double scalar) const{
        return {roll / scalar, pitch / scalar, yaw / scalar};
    }

    bool operator==(const Orientation& other) const{
        return roll == other.roll && pitch == other.pitch && yaw == other.yaw;
    }
};



#endif //WAVES_ORIENTATION_H
