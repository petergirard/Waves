//
// Created by Peter on 6/13/2024.
//

#ifndef WAVES_MANEUVERGOALSSTATE_H
#define WAVES_MANEUVERGOALSSTATE_H

struct ManeuverGoalsState{
public:
    double pitchGoal = 0;
    double pitchError = 0;
    double yawGoal = 0;
    double yawError = 0;
    double depthGoal = 0;
    double depthError = 0;
    double speedGoal = 0;
    double speedError = 0;

    ManeuverGoalsState() = default;
    ManeuverGoalsState(double pitchGoal_,
                       double pitchError_,
                       double yawGoal_,
                       double yawError_,
                       double depthGoal_,
                       double depthError_,
                       double speedGoal_,
                       double speedError_)
        : pitchGoal(pitchGoal_),
        pitchError(pitchError_),
        yawGoal(yawGoal_),
        yawError(yawError_),
        depthGoal(depthGoal_),
        depthError(depthError_),
        speedGoal(speedGoal_),
        speedError(speedError_) {}
    ManeuverGoalsState(const ManeuverGoalsState& other) = default;
};

#endif //WAVES_MANEUVERGOALSSTATE_H
