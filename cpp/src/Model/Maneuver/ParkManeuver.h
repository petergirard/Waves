//
// Created by Peter on 7/13/2024.
//

#ifndef WAVES_PARKMANEUVER_H
#define WAVES_PARKMANEUVER_H

#include "ManeuverBase.h"
#include "../Base/Point3D.h"

struct ParkManeuver : ManeuverBase {
public:
    Point3D parkLocation{}; // The location the vehicle will park at.
    double parkSpeed = 1.5; // The speed the vehicle will drive once at the park position.
    double parkRadius = 10; // The distance from the park location the vehicle can be while still be successfully parking.
    std::optional<Point3D> transitFromLocation{}; // The location the vehicle is transiting from.
    double transitDepth = 0; // The depth the vehicle should drive at while transiting to the park position.
    double transitSpeed = 1.5; // The speed the vehicle should drive at while transiting to the park position.

    ParkManeuver() = default;
    ParkManeuver(ManeuverCompletionCriteria completionCriteria_,
                 Point3D parkLocation_,
                 double parkSpeed_,
                 double transitDepth_,
                 double transitSpeed_)
                 : ManeuverBase(completionCriteria_),
                   parkLocation(parkLocation_),
                   parkSpeed(parkSpeed_),
                   transitDepth(transitDepth_),
                   transitSpeed(transitSpeed_) {
        if (completionCriteria_.proximityToGoal.has_value() || completionCriteria_.perpendicularToGoal.has_value())
            throw std::invalid_argument("ParkManeuver cannot accept proximityToGoal or perpendicularToGoal as completion criteria");
    }
};

#endif //WAVES_PARKMANEUVER_H
