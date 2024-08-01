//
// Created by Peter on 7/14/2024.
//

#ifndef WAVES_MANEUVERCOMMAND_H
#define WAVES_MANEUVERCOMMAND_H

#include <variant>
#include <memory>
#include <type_traits>
#include "../Maneuver/DriveToManeuver.h"
#include "../Maneuver/ParkManeuver.h"
#include "../Maneuver/PrimitiveManeuver.h"
#include "CommandBase.h"

template <typename T>
concept DerivedFromManeuverBase = std::is_base_of_v<ManeuverBase, T>;

template <DerivedFromManeuverBase TManeuver>
struct ManeuverCommand : public CommandBase {
public:
    TManeuver maneuver;
    ManeuverCommand() = default;
    ManeuverCommand(TManeuver maneuver_, TimePoint timeIssued_)
            : CommandBase(timeIssued_), maneuver(maneuver_) {}
};

#endif //WAVES_MANEUVERCOMMAND_H
