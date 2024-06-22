//
// Created by Peter on 6/14/2024.
//

#ifndef WAVES_VECTOR3D_H
#define WAVES_VECTOR3D_H

#include <complex>
#include "Vector2D.h"

struct Vector3D {
public:
    double x = 0;
    double y = 0;
    double z = 0;
    double magnitude = 0;

    Vector3D() = default;
    Vector3D(double x_, double y_, double z_)
        : x(x_), y(y_), z(z_), magnitude(std::sqrt(x_ * x_ + y_ * y_ + z_ * z_)) {}

    [[nodiscard]] Vector2D to2D() const{
        return {x, y};
    }

    Vector3D operator+(const Vector3D& v) const{
        return {x + v.x, y + v.y, z + v.z};
    }
    Vector3D operator-(const Vector3D& v) const{
        return {x - v.x, y - v.y, z - v.z};
    }
    Vector3D operator*(double scalar) const{
        return {x * scalar, y * scalar, z * scalar};
    }
    Vector3D operator/(double scalar) const{
        return {x / scalar, y / scalar, z / scalar};
    }
    bool operator==(const Vector3D& v) const{
        return x == v.x && y == v.y && z == v.z;
    }
};


#endif //WAVES_VECTOR3D_H
