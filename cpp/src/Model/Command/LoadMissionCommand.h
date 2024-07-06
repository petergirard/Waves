//
// Created by Peter on 7/6/2024.
//

#ifndef WAVES_LOADMISSIONCOMMAND_H
#define WAVES_LOADMISSIONCOMMAND_H

#include "../Mission/Mission.h"
#include "../Base/TimePoint.h"

class LoadMissionCommand{
public:
    Mission mission;
    TimePoint timePoint;
};

#endif //WAVES_LOADMISSIONCOMMAND_H
