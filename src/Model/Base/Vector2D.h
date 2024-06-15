//
// Created by Peter on 6/14/2024.
//

#ifndef WAVES_VECTOR2D_H
#define WAVES_VECTOR2D_H


#include <complex>

struct Vector2D {
public:
    double x = 0;
    double y = 0;
    double magnitude = 0;

    Vector2D() = default;
    Vector2D(double x_, double y_) : x(x_), y(y_), magnitude(std::sqrt(x_ * x_ + y_ * y_)) {}

    Vector2D operator+(const Vector2D& p) const{
        return {x + p.x, y + p.y};
    }
    Vector2D operator-(const Vector2D& p) const{
        return {x - p.x, y - p.y};
    }
    Vector2D operator*(double scalar) const{
        return {x * scalar, y * scalar};
    }
    Vector2D operator/(double scalar) const{
        return {x / scalar, y / scalar};
    }
    bool operator==(const Vector2D& p) const{
        return x == p.x && y == p.y;
    }
};


#endif //WAVES_VECTOR2D_H
