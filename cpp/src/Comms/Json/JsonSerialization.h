//
// Created by Peter on 6/24/2024.
//

#ifndef WAVES_JSONSERIALIZATION_H
#define WAVES_JSONSERIALIZATION_H

struct GoToLocationCommand;

#include "../../Model/Base/Orientation.h"
#include "../../Model/Base/Point2D.h"
#include "../../Model/Base/Point3D.h"
#include "../../Model/Base/TimePoint.h"
#include "../../Model/Base/Vector2D.h"
#include "../../Model/Base/Vector3D.h"
#include "../../Model/Maneuver/ManeuverControlsState.h"
#include "../../Model/Navigation/PhysicalState.h"
#include "../../Model/Maneuver/ManeuverGoalsState.h"
#include "../../Model/Misc/BatteryState.h"
#include "../../Model/Mission/Mission.h"
#include "../../Model/Mission/MissionExecutionState.h"
#include "../../Model/Mission/Waypoint.h"
#include "../../Model/Report/WavesStatusReport.h"
#include "../../Model/Command/LoadMissionCommand.h"
#include "../../Model/Command/RunMissionCommand.h"
#include "../../Model/Command/StopCommand.h"
#include "../../Model/Maneuver/DriveToManeuver.h"
#include "../../Model/Maneuver/ParkManeuver.h"
#include "../../Model/Maneuver/PrimitiveManeuver.h"
#include "../../Model/Command/ManeuverCommand.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Orientation
void to_json(json& j, const Orientation& o);
void from_json(const json& j, Orientation& o);

// Point2D
void to_json(json& j, const Point2D& p);
void from_json(const json& j, Point2D& p);

// Point3D
void to_json(json& j, const Point3D& p);
void from_json(const json& j, Point3D& p);

// Vector2D
void to_json(json& j, const Vector2D& v);
void from_json(const json& j, Vector2D& v);

// Vector3D
void to_json(json& j, const Vector3D& v);
void from_json(const json& j, Vector3D& v);

// ManeuverControlsState
void to_json(json& j, const ManeuverControlsState& m);
void from_json(const json& j, ManeuverControlsState& m);

// PhysicalState
void to_json(json& j, const PhysicalState& m);
void from_json(const json& j, PhysicalState& m);

// BatteryState
void to_json(json& j, const BatteryState& b);
void from_json(const json& j, BatteryState& b);

// Mission
void to_json(json& j, const Mission& m);
void from_json(const json& j, Mission& m);

// MissionExecutionState
void to_json(json& j, const MissionExecutionState& ms);
void from_json(const json& j, MissionExecutionState& ms);

// ManeuverGoalsState
void to_json(json& j, const ManeuverGoalsState& ns);
void from_json(const json& j, ManeuverGoalsState& ns);

// Waypoint
void to_json(json& j, const Waypoint& w);
void from_json(const json& j, Waypoint& w);

// TimePoint
void to_json(json& j, const TimePoint& tp);
void from_json(const json& j, TimePoint& tp);

// WavesStatusReport
void to_json(json& j, const WavesStatusReport& w);
void from_json(const json& j, WavesStatusReport& w);

// MANEUVERS
// ManeuverCompletionCriteria
void to_json(json& j, const ManeuverCompletionCriteria& m);
void from_json(const json& j, ManeuverCompletionCriteria& m);

// ManeuverBase
void to_json(json& j, const ManeuverBase& m);
void from_json(const json& j, ManeuverBase& m);

// DriveToManeuver
void to_json(json& j, const DriveToManeuver& m);
void from_json(const json& j, DriveToManeuver& m);

// ParkManeuver
void to_json(json& j, const ParkManeuver& m);
void from_json(const json& j, ParkManeuver& m);

// PrimitiveManeuver
void to_json(json& j, const PrimitiveManeuver& m);
void from_json(const json& j, PrimitiveManeuver& m);


// COMMANDS

// LoadMissionCommand
void to_json(json& j, const LoadMissionCommand& cmd);
void from_json(const json& j, LoadMissionCommand& cmd);

// RunMissionCommand
void to_json(json& j, const RunMissionCommand& cmd);
void from_json(const json& j, RunMissionCommand& cmd);

// StopCommand
void to_json(json& j, const StopCommand& cmd);
void from_json(const json& j, StopCommand& cmd);

// DriveToManeuverCommand
void to_json(json& j, const ManeuverCommand<DriveToManeuver>& command);
void from_json(const json& j, ManeuverCommand<DriveToManeuver>& command);

// ParkManeuverCommand
void to_json(json& j, const ManeuverCommand<ParkManeuver>& command);
void from_json(const json& j, ManeuverCommand<ParkManeuver>& command);

void to_json(json& j, const ManeuverCommand<PrimitiveManeuver>& command);
void from_json(const json& j, ManeuverCommand<PrimitiveManeuver>& command);


#endif //WAVES_JSONSERIALIZATION_H