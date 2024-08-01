//
// Created by Peter on 7/6/2024.
//

#include "CommandManager.h"
#include "../Model/Command/ManeuverCommand.h"
#include <functional>

CommandManager::CommandManager() {
    _commandProcessors.push_back(std::make_unique<CommandProcessor<LoadMissionCommand>>(
            "load_mission_command",
            [this](Pilot& vehicle, const LoadMissionCommand& command) { processLoadMissionCommand(vehicle, command); }
    ));
    _commandProcessors.push_back(std::make_unique<CommandProcessor<RunMissionCommand>>(
            "run_mission_command",
            [this](Pilot& vehicle, const RunMissionCommand& command) { processRunMissionCommand(vehicle, command); }
    ));
    _commandProcessors.push_back(std::make_unique<CommandProcessor<StopCommand>>(
            "stop_mission_command",
            [this](Pilot& vehicle, const StopCommand& command) { processStopMissionCommand(vehicle, command); }
    ));
    _commandProcessors.push_back(std::make_unique<CommandProcessor<ManeuverCommand<DriveToManeuver>>>(
            "drive_to_maneuver_command",
            [this](Pilot& vehicle, const ManeuverCommand<DriveToManeuver>& command) { processDriveToManeuverCommand(vehicle, command); }
    ));
    _commandProcessors.push_back(std::make_unique<CommandProcessor<ManeuverCommand<ParkManeuver>>>(
            "park_maneuver_command",
            [this](Pilot& vehicle, const ManeuverCommand<ParkManeuver>& command) { processParkManeuverCommand(vehicle, command); }
    ));
    _commandProcessors.push_back(std::make_unique<CommandProcessor<ManeuverCommand<PrimitiveManeuver>>>(
            "primitive_maneuver_command",
            [this](Pilot& vehicle, const ManeuverCommand<PrimitiveManeuver>& command) { processPrimitiveManeuverCommand(vehicle, command); }
    ));

    ParkManeuver parkManeuver{};
    TimePoint time{};
    ManeuverCommand<ParkManeuver> parkCommand(parkManeuver, time);
    parkCommand.maneuver.parkSpeed;
}

CommandManager::~CommandManager() = default;

void CommandManager::connect() {
    for (auto& processors : _commandProcessors) {
        processors->connect();
    }
}

void CommandManager::closeConnection() {
    for (auto& processors : _commandProcessors) {
        processors->closeConnection();
    }
}

void CommandManager::executeCommands(Pilot& vehicle) {
    for (const auto& processors : _commandProcessors) {
        processors->executeCommands(vehicle);
    }
}

void CommandManager::processLoadMissionCommand(Pilot& pilot, LoadMissionCommand command) {
    pilot.loadMission(std::move(command.mission));
}

void CommandManager::processRunMissionCommand(Pilot& pilot, const RunMissionCommand& command) {
    pilot.setActiveMission(command.missionName);
}

void CommandManager::processStopMissionCommand(Pilot& pilot, const StopCommand& command) {
    pilot.stop();
}

void CommandManager::processDriveToManeuverCommand(Pilot &pilot, const ManeuverCommand<DriveToManeuver> &command) {
    pilot.addCurrentManeuver(std::make_unique<DriveToManeuver>(command.maneuver));
}

void CommandManager::processParkManeuverCommand(Pilot &pilot, const ManeuverCommand<ParkManeuver> &command) {
    pilot.addCurrentManeuver(std::make_unique<ParkManeuver>(command.maneuver));
}

void CommandManager::processPrimitiveManeuverCommand(Pilot &pilot, const ManeuverCommand<PrimitiveManeuver> &command) {
    pilot.addCurrentManeuver(std::make_unique<PrimitiveManeuver>(command.maneuver));
}
