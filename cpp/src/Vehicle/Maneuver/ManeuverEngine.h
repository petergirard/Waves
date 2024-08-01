//
// Created by Peter on 7/13/2024.
//

#ifndef WAVES_MANEUVERENGINE_H
#define WAVES_MANEUVERENGINE_H


#include <stack>
#include <memory>
#include "../../Model/Maneuver/ManeuverBase.h"
#include "../../Model/Base/TimePoint.h"
#include "../../Model/Navigation/PhysicalState.h"
#include "../../Model/Maneuver/PrimitiveManeuver.h"
#include "PidController.h"
#include "ManeuverWrapper.h"

class ManeuverEngine {
public:
    [[nodiscard]] bool isUnderPrimitiveControl() const;
    [[nodiscard]] ManeuverControlsState getManeuverControlsState() const;
    [[nodiscard]] std::optional<ManeuverGoalsState> getManeuverGoalsState() const;

    // Updates the maneuver engine. Returns true if all the maneuvers have been completed, aka the _maneuverStack is empty.
    // This should single to the pilot that new maneuvers should be issued.
    bool update(const PhysicalState& physicalState, const TimePoint& time, const double& dt);
    void addManeuver(std::unique_ptr<ManeuverBase> maneuver);
    void reset();

private:
    std::optional<ManeuverControlsState> _primitiveControl{};
    std::optional<ManeuverGoalsState> _maneuverGoals{};
    std::optional<ManeuverWrapper> _activeManeuver{};
    PidController _pidController{};
    std::stack<ManeuverWrapper> _maneuverStack{};

    static bool isManeuverComplete(const ManeuverWrapper& wrapper,
                                   const PhysicalState& physicalState, const TimePoint& time);
    static bool isInsideParkRadius(const ParkManeuver &parkManeuver, const Point3D& vehiclePosition);
    static DriveToManeuver convertParkToDrive(const ParkManeuver& park);
    void goToNextManeuver();
};


#endif //WAVES_MANEUVERENGINE_H
