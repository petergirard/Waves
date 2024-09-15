//
// Created by Peter on 7/12/2024.
//

#ifndef WAVES_COMMANDPROCESSORBASE_H
#define WAVES_COMMANDPROCESSORBASE_H

#include "../Comms/IConnectable.h"
#include "../Pilot/Pilot.h"

class CommandProcessorBase : public IConnectable {
public:
    virtual void executeCommands(Pilot& vehicle) = 0;
    ~CommandProcessorBase() override = default;
};

#endif // WAVES_COMMANDPROCESSORBASE_H
