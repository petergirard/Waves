//
// Created by Peter on 7/6/2024.
//

#ifndef WAVES_STOPCOMMAND_H
#define WAVES_STOPCOMMAND_H

#include "../Base/TimePoint.h"

struct StopCommand : public CommandBase {
public:
    StopCommand() = default;
    explicit StopCommand(TimePoint timeIssued_) : CommandBase(timeIssued_) {}
};

#endif //WAVES_STOPCOMMAND_H
