//
// Created by Peter on 7/14/2024.
//

#ifndef WAVES_MANEUVERWRAPPER_H
#define WAVES_MANEUVERWRAPPER_H

#include <memory>
#include "../../Model/Maneuver/ManeuverBase.h"

struct ManeuverWrapper {
public:
    std::unique_ptr<ManeuverBase> maneuver{};
    std::chrono::duration<double> runTime{}; // time the maneuver has been running in seconds.
    ManeuverWrapper() = default;
    explicit ManeuverWrapper(std::unique_ptr<ManeuverBase> maneuver_) : maneuver(std::move(maneuver_)), runTime() {}
};

#endif //WAVES_MANEUVERWRAPPER_H
