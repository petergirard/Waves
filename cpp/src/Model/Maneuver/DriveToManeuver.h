//
// Created by Peter on 7/13/2024.
//

#ifndef WAVES_DRIVETOMANEUVER_H
#define WAVES_DRIVETOMANEUVER_H

#include "../Base/Point3D.h"
#include "ManeuverBase.h"

struct DriveToManeuver : public ManeuverBase {
public:
    Point3D toPosition{}; // the position the vehicle should drive to.
    std::optional<Point3D> fromPosition{}; // if not null, the vehicle will drive along a line defined by "to" and "from" positions.
    double speed = 0; // the speed the vehicle should drive at in m/s.

    DriveToManeuver() = default;
    DriveToManeuver( ManeuverCompletionCriteria completionCriteria_,
                     Point3D driveToLocation,
                     std::optional<Point3D> driveFromLocation_,
                     double speed_)
                     : ManeuverBase(completionCriteria_),
                       toPosition(driveToLocation),
                       fromPosition(driveFromLocation_),
                       speed(speed_) {
        if (completionCriteria_.perpendicularToGoal.has_value() && !driveFromLocation_.has_value())
            throw std::invalid_argument("DriveToManeuver cannot accept perpendicularToGoal as a completion criteria without a fromPosition.");
    }
};

#endif //WAVES_DRIVETOMANEUVER_H
