//
// Created by Peter on 7/13/2024.
//

#ifndef WAVES_PRIMITIVEMANEUVER_H
#define WAVES_PRIMITIVEMANEUVER_H

#include "ManeuverBase.h"
#include "ManeuverControlsState.h"

struct PrimitiveManeuver : ManeuverBase {
public:
    ManeuverControlsState controlsState{};
    PrimitiveManeuver() = default;
    PrimitiveManeuver(ManeuverCompletionCriteria completionCriteria_, ManeuverControlsState controlsState_)
    : ManeuverBase(completionCriteria_), controlsState(controlsState_) {
        if (completionCriteria_.perpendicularToGoal.has_value() || completionCriteria_.proximityToGoal.has_value())
            throw std::invalid_argument("PrimitiveManeuver cannot accept proximityToGoal or perpendicularToGoal as completion criteria");
    }
};

#endif //WAVES_PRIMITIVEMANEUVER_H
