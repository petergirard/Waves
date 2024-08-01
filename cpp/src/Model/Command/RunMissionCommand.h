//
// Created by Peter on 7/6/2024.
//

#ifndef WAVES_RUNMISSIONCOMMAND_H
#define WAVES_RUNMISSIONCOMMAND_H

#include <string>
#include <utility>
#include "../Base/TimePoint.h"
#include "CommandBase.h"

struct RunMissionCommand : public CommandBase {
public:
    std::string missionName;
    RunMissionCommand() = default;
    RunMissionCommand(std::string missionName_, TimePoint timeIssued_)
    : CommandBase(timeIssued_), missionName(std::move(missionName_)) {}
};

#endif //WAVES_RUNMISSIONCOMMAND_H
