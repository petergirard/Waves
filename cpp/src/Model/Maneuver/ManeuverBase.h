//
// Created by Peter on 7/13/2024.
//

#ifndef WAVES_MANEUVERBASE_H
#define WAVES_MANEUVERBASE_H

#include <vector>
#include <stdexcept>
#include "ManeuverCompletionCriteria.h"
#include "../Base/TimePoint.h"

struct ManeuverBase{
public:
    ManeuverCompletionCriteria completionCriteria{};
    ManeuverBase() = default;
    explicit ManeuverBase(ManeuverCompletionCriteria completionCriteria_) : completionCriteria(completionCriteria_) {}
    virtual ~ManeuverBase() = default;
};

#endif //WAVES_MANEUVERBASE_H
