#include <thread>
#include <chrono>
#include "src/Model/Mission/Mission.h"
#include "src/Pilot/Pilot.h"
#include "src/Sim/SimplePhysics.h"
#include "src/Sim/Display.h"
#include "src/Comms/RabbitMQ/RabbitPublisher.h"
#include "src/Comms/Json/JsonSerialization.h"
#include "src/Control/CommandManager.h"
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;

int main() {

    try {
        Pilot pilot{};
        SimplePhysics physics{}; // simulator
        Display display{};

        PhysicalState physicalState{};

        auto initialTime = std::chrono::time_point_cast<std::chrono::duration<double>>(
                std::chrono::system_clock::now());
        auto currentTime = initialTime;
        double runTimeSeconds = 0;
        double dt = 1;
        bool running = true;

        CommandManager commandManager{};
        RabbitPublisher<WavesStatusReport> publisher("waves_status_message");

        commandManager.connect();
        publisher.connect();

        while (running) {

            commandManager.processCommands(pilot);

            pilot.update(physicalState, currentTime, dt);
            physicalState = physics.update(physicalState, pilot.getManeuverControlsState(), dt);
            display.displayStats(physicalState, pilot.getManeuverControlsState());

            WavesStatusReport wavesStatusMessage(pilot.getManeuverControlsState(),
                                                 physicalState,
                                                 pilot.getMissionState(),
                                                 pilot.getManeuverGoalsState(),
                                                 pilot.getBatteryState(),
                                                 currentTime,
                                                 runTimeSeconds);

            publisher.publish(wavesStatusMessage);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            runTimeSeconds += dt;
            currentTime = initialTime + std::chrono::duration<double>(runTimeSeconds);
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception caught" << std::endl;
    }
}