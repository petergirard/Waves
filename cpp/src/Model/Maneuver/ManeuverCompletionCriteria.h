//
// Created by Peter on 7/13/2024.
//

#ifndef WAVES_MANEUVERCOMPLETIONCRITERIA_H
#define WAVES_MANEUVERCOMPLETIONCRITERIA_H

#include <optional>
#include "../Base/TimePoint.h"

struct ManeuverCompletionCriteria {
    // Maneuver is complete when within a certain distance to a location.
    std::optional<double> proximityToGoal{};

    // Maneuver is complete when vehicle is passed the line that is perpendicular to the drive line and goes through the goal location (only allowed for DriveAlongLineManeuver).
    // NOTE: Not implemented yet.
    std::optional<bool> perpendicularToGoal{};

    // Maneuver is complete after time is reached.
    std::optional<TimePoint> completionTime{};

    // Maneuver is complete after running for a certain duration
    std::optional<std::chrono::duration<double>> duration{};

    // Maneuver is complete once a depth is reached.
    std::optional<double> depthReached{};

    ManeuverCompletionCriteria() = default;
    ManeuverCompletionCriteria(std::optional<double> proximityToGoal_,
                               std::optional<bool> perpendicularToGoal_,
                               std::optional<TimePoint> completionTime_,
                               std::optional<std::chrono::duration<double>> duration_,
                               std::optional<double> depthReached_)
                               : proximityToGoal(proximityToGoal_),
                                 perpendicularToGoal(perpendicularToGoal_),
                                 completionTime(completionTime_),
                                 duration(duration_),
                                 depthReached(depthReached_) {};
};

#endif //WAVES_MANEUVERCOMPLETIONCRITERIA_H
