//
// Created by Peter on 7/6/2024.
//

#ifndef WAVES_LOADMISSIONCOMMAND_H
#define WAVES_LOADMISSIONCOMMAND_H

#include "../Mission/Mission.h"
#include "../Base/TimePoint.h"
#include "CommandBase.h"

struct LoadMissionCommand : public CommandBase {
public:
    Mission mission;
    LoadMissionCommand() = default;
    LoadMissionCommand(const Mission& mission_, TimePoint timeIssued_)
    : CommandBase(timeIssued_), mission(mission_) {}
};

#endif //WAVES_LOADMISSIONCOMMAND_H
