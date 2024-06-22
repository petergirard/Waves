//
// Created by Peter on 6/13/2024.
//

#ifndef WAVES_NAVIGATIONSTATUS_H
#define WAVES_NAVIGATIONSTATUS_H

class NavigationStatus{
public:
    double distanceToWaypoint = 0;
    double yawError = 0;
    double depthError = 0;
    double speedError = 0;

    NavigationStatus() = default;
    NavigationStatus(double distanceToWaypoint_, double yawError_, double depthError_, double speedError_)
        : distanceToWaypoint(distanceToWaypoint_), yawError(yawError_), depthError(depthError_), speedError(speedError_) {}
    NavigationStatus(const NavigationStatus& other) = default;
};

#endif //WAVES_NAVIGATIONSTATUS_H
