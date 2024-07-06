#include <iostream>
#include <thread>
#include <chrono>
#include "src/Model/Mission/Mission.h"
#include "src/Vehicle/VehicleMain.h"
#include "src/Sim/SimplePhysics.h"
#include "src/Sim/Physics.h"
#include "src/Sim/Display.h"
#include "src/Comms/RabbitMQ/RabbitPublisher.h"
#include "src/Comms/JsonSerialization.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

Mission constructMission(){
    Waypoint wp1 = {Point2D(50, 50), 10, 1.5, 10};
    Waypoint wp2 = {Point2D(50, 0), 10, 1.5, 10};
    Waypoint wp3 = {Point2D(0, 50), 10, 1.5, 10};
    Waypoint wp4 = {Point2D(0, 0), 10, 1.5, 10};
    return Mission("Test1", {wp1, wp2, wp3, wp4});
}

int main() {

    VehicleMain vehicle{};
    SimplePhysics physics{}; // simulator
    Display display{};

    vehicle.runMission(constructMission());
    PhysicalState maneuverState{};

    auto initialTime = std::chrono::time_point_cast<std::chrono::duration<double>>(std::chrono::system_clock::now());
    auto currentTime = initialTime;
    double runTimeSeconds = 0;
    double dt = 1;
    bool running = true;

    RabbitPublisher rabbitPublisher("localhost", "waves_status_message", "fanout");
    rabbitPublisher.connect();

    while(running){

        vehicle.update(maneuverState, currentTime);
        maneuverState = physics.update(maneuverState, vehicle.getManeuverControlsState(), dt);
        display.displayStats(maneuverState, vehicle.getManeuverControlsState());

        WavesStatusMessage wavesStatusMessage(vehicle.getManeuverControlsState(),
                                              maneuverState,
                                              vehicle.getMissionState(),
                                              vehicle.getManeuverGoalsState(),
                                              currentTime,
                                              runTimeSeconds);

        json j = wavesStatusMessage;
        rabbitPublisher.publishMessage(j.dump(4));


        std::this_thread::sleep_for(std::chrono::milliseconds(100));

//        // Check for user input to quit
//        if (std::cin.peek() == 'q' || std::cin.peek() == 'Q') {
//            running = false;
//        }

        runTimeSeconds += dt;
        currentTime = initialTime + std::chrono::duration<double>(runTimeSeconds);
    }

}
