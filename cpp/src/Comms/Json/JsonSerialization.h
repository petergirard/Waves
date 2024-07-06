//
// Created by Peter on 6/24/2024.
//

#ifndef WAVES_JSONSERIALIZATION_H
#define WAVES_JSONSERIALIZATION_H

//#include "../../Model/Base/Orientation.h"
//#include "../../Model/Base/Point2D.h"
//#include "../../Model/Base/Point3D.h"
//#include "../../Model/Base/TimePoint.h"
//#include "../../Model/Base/Vector2D.h"
//#include "../../Model/Base/Vector3D.h"
//#include "../../Model/Maneuver/ManeuverControlsState.h"
//#include "../../Model/Maneuver/PhysicalState.h"
//#include "../../Model/Maneuver/ManeuverGoalsState.h"
//#include "../../Model/Misc/BatteryState.h"
//#include "../../Model/Mission/Mission.h"
//#include "../../Model/Mission/MissionState.h"
//#include "../../Model/Mission/Waypoint.h"
#include "../../Model/Report/WavesStatusReport.h"
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

// MissionState
void to_json(json& j, const MissionState& ms);
void from_json(const json& j, MissionState& ms);

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


#endif //WAVES_JSONSERIALIZATION_H