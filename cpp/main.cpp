#include <iostream>
#include <thread>
#include <chrono>
#include "src/Model/Mission/Mission.h"
#include "src/Vehicle/VehicleMain.h"
#include "src/Sim/Physics.h"
#include "src/Sim/Display.h"

Mission constructMission(){
    Waypoint wp2 = {Point2D(50, 50), 10, 1.5, 10};
    Waypoint wp1 = {Point2D(50, 0), 10, 1.5, 10};
    Waypoint wp3 = {Point2D(0, 50), 10, 1.5, 10};
    Waypoint wp4 = {Point2D(0, 0), 10, 1.5, 10};
    return Mission("Test1", {wp1, wp2, wp3, wp4});
}


int main() {

    VehicleMain vehicle{};
    Physics physics{}; // simulator
    Display display{};

    vehicle.runMission(constructMission());
    ManeuverState maneuverState{};

    auto initialTime = std::chrono::time_point_cast<std::chrono::duration<double>>(std::chrono::system_clock::now());
    auto currentTime = initialTime;
    double runTimeSeconds = 0;
    double dt = 0.1;
    int i = 0;
    bool running = true;

    while(running){
        vehicle.update(maneuverState, currentTime);
        maneuverState = physics.update(maneuverState, vehicle.getManeuverControls(), dt);
        display.displayStats(maneuverState, vehicle.getManeuverControls());

        std::this_thread::sleep_for(std::chrono::milliseconds(100));

//        // Check for user input to quit
//        if (std::cin.peek() == 'q' || std::cin.peek() == 'Q') {
//            running = false;
//        }

        runTimeSeconds += dt;
        currentTime = initialTime + std::chrono::duration<double>(runTimeSeconds);
    }

}
