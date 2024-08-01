//
// Created by Peter on 6/4/2024.
//

#ifndef WAVES_DISPLAY_H
#define WAVES_DISPLAY_H


#include <vector>
#include "../Model/Navigation/PhysicalState.h"
#include "../Model/Maneuver/ManeuverControlsState.h"

class Display {
public:
    void displayStats(const PhysicalState& state, const ManeuverControlsState& controls);

private:
    std::vector<std::string> screenBuffer;

    void clearScreen();
    void printScreen();
    void updateScreenBuffer(const std::string& newDisplay);

    std::string renderDisplay(const PhysicalState& state, const ManeuverControlsState& controls);
    void getStateDisplay(std::ostringstream &oss, const PhysicalState& state);
    void getManeuverDisplay(std::ostringstream &oss, const ManeuverControlsState& controls);
};


#endif //WAVES_DISPLAY_H
