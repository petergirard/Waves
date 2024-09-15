//
// Created by Peter on 7/6/2024.
//

#ifndef WAVES_COMMANDMANAGER_H
#define WAVES_COMMANDMANAGER_H

#include <vector>
#include <functional>
#include "../Pilot/Pilot.h"
#include "../Comms/RabbitMQ/RabbitSubscriber.h"
#include "../Model/Command/LoadMissionCommand.h"
#include "../Model/Command/RunMissionCommand.h"
#include "../Model/Command/StopCommand.h"
#include "CommandProcessor.h"
#include "../Model/Command/ManeuverCommand.h"

class CommandManager : public IConnectable {
public:
    CommandManager();
    ~CommandManager() override;

    void connect() override;
    void closeConnection() override;
    void processCommands(Pilot& vehicle);

private:
    std::vector<std::unique_ptr<CommandProcessorBase>> _commandProcessors;
    ConcurrentQueue<std::unique_ptr<CommandBase>> _commandQueue;

    static void processLoadMissionCommand(Pilot& pilot, LoadMissionCommand command);
    static void processRunMissionCommand(Pilot& pilot, const RunMissionCommand& command);
    static void processStopMissionCommand(Pilot& pilot, const StopCommand& command);
    static void processDriveToManeuverCommand(Pilot& pilot, const ManeuverCommand<DriveToManeuver>& command);
    static void processParkManeuverCommand(Pilot& pilot, const ManeuverCommand<ParkManeuver>& command);
    static void processPrimitiveManeuverCommand(Pilot& pilot, const ManeuverCommand<PrimitiveManeuver>& command);
};

#endif // WAVES_COMMANDMANAGER_H
