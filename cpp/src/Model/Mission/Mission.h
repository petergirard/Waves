//
// Created by Peter on 6/4/2024.
//

#ifndef WAVES_MISSION_H
#define WAVES_MISSION_H


#include <utility>

#include "Waypoint.h"
#include "vector"

struct Mission {
public:
    std::string name{};
    std::vector<Waypoint> waypoints{};
    Mission() = default;
    explicit Mission(std::string name_, const std::vector<Waypoint>& waypoints_)
        : name(std::move(name_)), waypoints(waypoints_) {}
    Mission(const Mission& other) : waypoints(other.waypoints) {}
};


#endif //WAVES_MISSION_H
