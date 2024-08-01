//
// Created by Peter on 7/14/2024.
//

#ifndef WAVES_COMMANDBASE_H
#define WAVES_COMMANDBASE_H

#include "../Base/TimePoint.h"

struct CommandBase {
    TimePoint timeIssued{};
    CommandBase() = default;
    explicit CommandBase(TimePoint timeIssued_) : timeIssued(timeIssued_) {}
};

#endif //WAVES_COMMANDBASE_H
