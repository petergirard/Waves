//
// Created by Peter on 6/4/2024.
//

#ifndef WAVES_WAYPOINT_H
#define WAVES_WAYPOINT_H


#include "../Base/Point3D.h"

struct Waypoint {
public:
    Point3D position{}; // Position of the waypoint.
    double speed = 0; // Speed in meters / sec
    double successRadius = 0; // Distance vehicle must be from WP before being considered "achieved".

    Waypoint() = default;
    Waypoint(const Waypoint& other) = default;
    Waypoint(Point3D position_, double speed_, double successRadius_)
        : position(position_), speed(speed_), successRadius(successRadius_) {}
};


#endif //WAVES_WAYPOINT_H
