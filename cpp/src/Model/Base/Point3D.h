//
// Created by Peter on 6/14/2024.
//

#ifndef WAVES_POINT3D_H
#define WAVES_POINT3D_H

#include "Vector3D.h"
#include "Point2D.h"

struct Point3D {
    double x = 0;
    double y = 0;
    double z = 0;

    Point3D() = default;
    Point3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

    [[nodiscard]] Point2D to2D() const{
        return {x, y};
    }

    Point3D operator+(const Vector3D& v) const{
        return {x + v.x, y + v.y, z + v.z};
    }
    Point3D operator-(const Vector3D& v) const{
        return {x - v.x, y - v.y, z - v.z};
    }
    Vector3D operator+(const Point3D& p) const{
        return {x + p.x, y + p.y, z + p.z};
    }
    Vector3D operator-(const Point3D& p) const {
        return {x - p.x, y - p.y, z - p.z};
    }
    bool operator==(const Point3D& p) const{
        return x == p.x && y == p.y && z == p.z;
    }

    [[nodiscard]] Vector3D vectorTo(const Point3D& other) const{
        return {other.x - x, other.y - y, other.z - z};
    }
};


#endif //WAVES_POINT3D_H
