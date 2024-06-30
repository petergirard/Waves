//
// Created by Peter on 6/24/2024.
//

#ifndef WAVES_JSONSERIALIZATION_H
#define WAVES_JSONSERIALIZATION_H

#include "../Model/Base/Orientation.h"
#include "../Model/Base/Point2D.h"
#include "../Model/Base/Point3D.h"
#include "../Model/Base/TimePoint.h"
#include "../Model/Base/Vector2D.h"
#include "../Model/Base/Vector3D.h"
#include "../Model/Maneuver/ManeuverControls.h"
#include "../Model/Maneuver/ManeuverState.h"
#include "../Model/Mission/Mission.h"
#include "../Model/Mission/MissionStatus.h"
#include "../Model/Mission/NavigationStatus.h"
#include "../Model/Mission/Waypoint.h"
#include "WavesStatusMessage.h"
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

// ManeuverControls
void to_json(json& j, const ManeuverControls& m);
void from_json(const json& j, ManeuverControls& m);

// ManeuverState
void to_json(json& j, const ManeuverState& m);
void from_json(const json& j, ManeuverState& m);

// Mission
void to_json(json& j, const Mission& m);
void from_json(const json& j, Mission& m);

// MissionStatus
void to_json(json& j, const MissionStatus& ms);
void from_json(const json& j, MissionStatus& ms);

// NavigationStatus
void to_json(json& j, const NavigationStatus& ns);
void from_json(const json& j, NavigationStatus& ns);

// Waypoint
void to_json(json& j, const Waypoint& w);
void from_json(const json& j, Waypoint& w);

// TimePoint
void to_json(json& j, const TimePoint& tp);
void from_json(const json& j, TimePoint& tp);

// WavesStatusMessage
void to_json(json& j, const WavesStatusMessage& w);
void from_json(const json& j, WavesStatusMessage& w);


#endif //WAVES_JSONSERIALIZATION_H