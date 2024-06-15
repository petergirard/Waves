//
// Created by Peter on 6/4/2024.
//

#include <iostream>
#include <iomanip>
#include "Display.h"

void Display::displayStats(const ManeuverState &state, const ManeuverControls &controls) {
    std::string display = renderDisplay(state, controls);
    updateScreenBuffer(display);
    printScreen();
}

void Display::updateScreenBuffer(const std::string& newDisplay) {
    // Split the newDisplay into lines
    std::vector<std::string> newBuffer;
    size_t pos = 0, end;
    while ((end = newDisplay.find('\n', pos)) != std::string::npos) {
        newBuffer.push_back(newDisplay.substr(pos, end - pos));
        pos = end + 1;
    }

    // Update the screen buffer with only changed lines
    for (size_t i = 0; i < newBuffer.size(); ++i) {
        if (i >= screenBuffer.size() || screenBuffer[i] != newBuffer[i]) {
            if (i < screenBuffer.size()) {
                screenBuffer[i] = newBuffer[i];
            } else {
                screenBuffer.push_back(newBuffer[i]);
            }
            // Move the cursor to the correct position and print the updated line
            std::cout << "\033[" << i + 1 << ";1H" << newBuffer[i];
        }
    }

    // Clear any extra lines from the previous frame
    if (screenBuffer.size() > newBuffer.size()) {
        for (size_t i = newBuffer.size(); i < screenBuffer.size(); ++i) {
            std::cout << "\033[" << i + 1 << ";1H" << std::string(screenBuffer[i].size(), ' ');
        }
        screenBuffer.resize(newBuffer.size());
    }
}


std::string Display::renderDisplay(const ManeuverState &state, const ManeuverControls &controls) {
    std::ostringstream oss;
    oss << "\n------------------------------------------\n";
    oss << "Current State:\n";
    getStateDisplay(oss, state);
    oss << "------------------------------------------\n";
    oss << "Maneuver Controls:\n";
    getManeuverDisplay(oss, controls);
    oss << "------------------------------------------\n";
    // oss << "Press 'Q' to quit";
    return oss.str();
}

void Display::getStateDisplay(std::ostringstream &oss, const ManeuverState &state) {
    oss << "Position: (" << std::setw(6) << state.position.x << ", " << std::setw(6) << state.position.y << ", " << std::setw(6) << state.position.z << ") meters\n";
    oss << "Velocity (World Frame): (" << std::setw(6) << state.velocityWorldFrame.x << ", " << std::setw(6) << state.velocityWorldFrame.y << ", " << std::setw(6) << state.velocityWorldFrame.z << ") m/s\n";
    oss << "Acceleration (World Frame): (" << std::setw(6) << state.accelerationWorldFrame.x << ", " << std::setw(6) << state.accelerationWorldFrame.y << ", " << std::setw(6) << state.accelerationWorldFrame.z << ") m/s^2\n";
    oss << "Velocity (Vehicle Frame): (" << std::setw(6) << state.velocityVehicleFrame.x << ", " << std::setw(6) << state.velocityVehicleFrame.y << ", " << std::setw(6) << state.velocityVehicleFrame.z << ") m/s\n";
    oss << "Acceleration (Vehicle Frame): (" << std::setw(6) << state.accelerationVehicleFrame.x << ", " << std::setw(6) << state.accelerationVehicleFrame.y << ", " << std::setw(6) << state.accelerationVehicleFrame.z << ") m/s^2\n";
    oss << "Attitude: (" << std::setw(6) << state.attitude.roll << ", " << std::setw(6) << state.attitude.pitch << ", " << std::setw(6) << state.attitude.yaw << ") degrees\n";
    oss << "Attitude Velocity: (" << std::setw(6) << state.attitudeVelocity.roll << ", " << std::setw(6) << state.attitudeVelocity.pitch << ", " << std::setw(6) << state.attitudeVelocity.yaw << ") degrees/s\n";
    oss << "Attitude Acceleration: (" << std::setw(6) << state.attitudeAcceleration.roll << ", " << std::setw(6) << state.attitudeAcceleration.pitch << ", " << std::setw(6) << state.attitudeAcceleration.yaw << ") degrees/s^2\n";
}

void Display::getManeuverDisplay(std::ostringstream &oss, const ManeuverControls &controls) {
    oss << "Elevator: " << std::setw(6) << controls.elevator << " (-1 to 1)\n";
    oss << "Rudder: " << std::setw(6) << controls.rudder << " (-1 to 1)\n";
    oss << "Throttle: " << std::setw(6) << controls.throttle << " (0 to 1)\n";
}

void Display::clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

void Display::printScreen() {
    std::flush(std::cout);
}

