//
// Created by Peter on 6/4/2024.
//

#ifndef WAVES_DISPLAY_H
#define WAVES_DISPLAY_H


#include <vector>
#include "../Model/Maneuver/ManeuverState.h"
#include "../Model/Maneuver/ManeuverControls.h"

class Display {
public:
    void displayStats(const ManeuverState& state, const ManeuverControls& controls);

private:
    std::vector<std::string> screenBuffer;

    void clearScreen();
    void printScreen();
    void updateScreenBuffer(const std::string& newDisplay);

    std::string renderDisplay(const ManeuverState& state, const ManeuverControls& controls);
    void getStateDisplay(std::ostringstream &oss, const ManeuverState& state);
    void getManeuverDisplay(std::ostringstream &oss, const ManeuverControls& controls);
};


#endif //WAVES_DISPLAY_H
