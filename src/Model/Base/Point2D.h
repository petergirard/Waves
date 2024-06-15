//
// Created by Peter on 6/4/2024.
//

#ifndef WAVES_POINT2D_H
#define WAVES_POINT2D_H

#include <complex>
#include "../../Util/UnitConversion.h"
#include "Vector2D.h"

struct Point2D {
public:
    double x = 0;
    double y = 0;

    Point2D() = default;
    Point2D(double x_, double y_) : x(x_), y(y_) {}

    bool operator==(const Point2D& p) const{
        return x == p.x && y == p.y;
    }

    Point2D operator+(const Vector2D& v) const{
        return {x + v.x, y + v.y};
    }
    Point2D operator-(const Vector2D& v) const{
        return {x - v.x, y - v.y};
    }

    [[nodiscard]] Vector2D vectorTo(const Point2D& other) const{
        return {other.x - x, other.y - y};
    }

    [[nodiscard]] double distanceTo(const Point2D& other) const{
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }

    [[nodiscard]] double angleTo(const Point2D& other) const {
        Point2D v1 = *this;
        Point2D v2 = other;

        double dotProduct = v1.x * v2.x + v1.y * v2.y;
        double crossProduct = v1.x * v2.y - v1.y * v2.x;
        double angleRadians = std::atan2(crossProduct, dotProduct);
        return UnitConversion::toDegrees(angleRadians);
    }
};

#endif //WAVES_POINT2D_H
