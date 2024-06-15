//
// Created by Peter on 6/4/2024.
//

#ifndef WAVES_WAYPOINT_H
#define WAVES_WAYPOINT_H


#include "../Base/Point2D.h"

struct Waypoint {
public:
    Point2D position = Point2D(); // Position of the waypoint.
    double depth = 0; // Distance below surface in meters. Positive down.
    double speed = 0; // Speed in meters / sec
    double successRadius = 0; // Distance vehicle must be from WP before being considered "achieved".

    Waypoint() = default;
    Waypoint(const Waypoint& other) = default;
    Waypoint(Point2D position_, double depth_, double speed_, double successRadius_)
        : position(position_), depth(depth_), speed(speed_), successRadius(successRadius_) {}
};


#endif //WAVES_WAYPOINT_H
