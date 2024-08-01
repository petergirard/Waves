#include <thread>
#include <chrono>
#include "src/Model/Mission/Mission.h"
#include "src/Vehicle/Pilot.h"
#include "src/Sim/SimplePhysics.h"
#include "src/Sim/Display.h"
#include "src/Comms/RabbitMQ/RabbitPublisher.h"
#include "src/Comms/Json/JsonSerialization.h"
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;

Mission constructMission(){
    Waypoint wp1(Point3D(50, 50, 10), 1.5, 10);
    Waypoint wp2(Point3D(50, 0, 10), 1.5, 10);
    Waypoint wp3(Point3D(0, 50, 10), 1.5, 10);
    Waypoint wp4(Point3D(0, 0, 10), 1.5, 10);
    return Mission("Test1", {wp1, wp2, wp3, wp4});
}

int main() {

    try {
        Pilot pilot{};
        SimplePhysics physics{}; // simulator
        Display display{};

        auto mission = constructMission();
        pilot.loadMission(std::move(mission));
        pilot.setActiveMission("Test1");

        PhysicalState physicalState{};

        auto initialTime = std::chrono::time_point_cast<std::chrono::duration<double>>(
                std::chrono::system_clock::now());
        auto currentTime = initialTime;
        double runTimeSeconds = 0;
        double dt = 1;
        bool running = true;

        RabbitPublisher<WavesStatusReport> publisher("waves_status_message");
        publisher.connect();

        while (running) {

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

//        // Check for user input to quit
//        if (std::cin.peek() == 'q' || std::cin.peek() == 'Q') {
//            running = false;
//        }

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