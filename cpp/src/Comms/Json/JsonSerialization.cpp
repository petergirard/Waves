//
// Created by Peter on 6/24/2024.
//

#include "JsonSerialization.h"

// Orientation
void to_json(json& j, const Orientation& o) {
    j = json{{"roll", o.roll}, {"pitch", o.pitch}, {"yaw", o.yaw}};
}

void from_json(const json& j, Orientation& o) {
    j.at("roll").get_to(o.roll);
    j.at("pitch").get_to(o.pitch);
    j.at("yaw").get_to(o.yaw);
}

// Point2D
void to_json(json& j, const Point2D& p) {
    j = json{{"x", p.x}, {"y", p.y}};
}

void from_json(const json& j, Point2D& p) {
    j.at("x").get_to(p.x);
    j.at("y").get_to(p.y);
}

// Point3D
void to_json(json& j, const Point3D& p) {
    j = json{{"x", p.x}, {"y", p.y}, {"z", p.z}};
}

void from_json(const json& j, Point3D& p) {
    j.at("x").get_to(p.x);
    j.at("y").get_to(p.y);
    j.at("z").get_to(p.z);
}

// Vector2D
void to_json(json& j, const Vector2D& v) {
    j = json{{"x", v.x}, {"y", v.y}, {"magnitude", v.magnitude}};
}

void from_json(const json& j, Vector2D& v) {
    j.at("x").get_to(v.x);
    j.at("y").get_to(v.y);
    j.at("magnitude").get_to(v.magnitude);
}

// Vector3D
void to_json(json& j, const Vector3D& v) {
    j = json{{"x", v.x}, {"y", v.y}, {"z", v.z}, {"magnitude", v.magnitude}};
}

void from_json(const json& j, Vector3D& v) {
    j.at("x").get_to(v.x);
    j.at("y").get_to(v.y);
    j.at("z").get_to(v.z);
    j.at("magnitude").get_to(v.magnitude);
}

// ManeuverControlsState
void to_json(json& j, const ManeuverControlsState& m) {
    j = json{{"pitchGoal", m.pitchGoal}, {"elevator", m.elevator}, {"rudder", m.rudder}, {"throttle", m.throttle}};
}

void from_json(const json& j, ManeuverControlsState& m) {
    j.at("pitchGoal").get_to(m.pitchGoal);
    j.at("elevator").get_to(m.elevator);
    j.at("rudder").get_to(m.rudder);
    j.at("throttle").get_to(m.throttle);
}

// ManeuverGoalsState
void to_json(json& j, const ManeuverGoalsState& ns) {
    j = json{
            {"yawGoal", ns.yawGoal},
            {"yawError", ns.yawError},
            {"depthGoal", ns.depthGoal},
            {"depthError", ns.depthError},
            {"speedGoal", ns.speedGoal},
            {"speedError", ns.speedError}
    };
}

void from_json(const json& j, ManeuverGoalsState& ns) {
    j.at("yawGoal").get_to(ns.yawGoal);
    j.at("yawError").get_to(ns.yawError);
    j.at("depthGoal").get_to(ns.depthGoal);
    j.at("depthError").get_to(ns.depthError);
    j.at("speedGoal").get_to(ns.speedGoal);
    j.at("speedError").get_to(ns.speedError);
}

// PhysicalState
void to_json(json& j, const PhysicalState& m) {
    j = json{
            {"position", m.position},
            {"velocityWorldFrame", m.velocityWorldFrame},
            {"accelerationWorldFrame", m.accelerationWorldFrame},
            {"velocityVehicleFrame", m.velocityVehicleFrame},
            {"accelerationVehicleFrame", m.accelerationVehicleFrame},
            {"attitude", m.attitude},
            {"attitudeVelocity", m.attitudeVelocity},
            {"attitudeAcceleration", m.attitudeAcceleration}
    };
}

void from_json(const json& j, PhysicalState& m) {
    j.at("position").get_to(m.position);
    j.at("velocityWorldFrame").get_to(m.velocityWorldFrame);
    j.at("accelerationWorldFrame").get_to(m.accelerationWorldFrame);
    j.at("velocityVehicleFrame").get_to(m.velocityVehicleFrame);
    j.at("accelerationVehicleFrame").get_to(m.accelerationVehicleFrame);
    j.at("attitude").get_to(m.attitude);
    j.at("attitudeVelocity").get_to(m.attitudeVelocity);
    j.at("attitudeAcceleration").get_to(m.attitudeAcceleration);
}

// BatteryState
void to_json(json& j, const BatteryState& b) {
    j = json{{"percentRemaining", b.percentRemaining}, {"wattHoursRemaining", b.wattHoursRemaining}};
}

void from_json(const json& j, BatteryState& b) {
    j.at("percentRemaining").get_to(b.percentRemaining);
    j.at("wattHoursRemaining").get_to(b.wattHoursRemaining);
}

// Mission
void to_json(json& j, const Mission& m) {
    j = json{{"name", m.name}, {"waypoints", m.waypoints}};
}

void from_json(const json& j, Mission& m) {
    j.at("name").get_to(m.name);
    j.at("waypoints").get_to(m.waypoints);
}

// MissionState
void to_json(json& j, const MissionState& ms) {
    j = json{
            {"activeMissionState", ms.activeMissionState},
            {"activeMission", ms.activeMission},
            {"activeWaypoint", ms.activeWaypoint},
            {"activeWaypointIndex", ms.activeWaypointIndex},
            {"distanceToWaypoint", ms.distanceToWaypoint}
    };
}

void from_json(const json& j, MissionState& ms) {
    j.at("activeMissionState").get_to(ms.activeMissionState);
    j.at("activeMission").get_to(ms.activeMission);
    j.at("activeWaypoint").get_to(ms.activeWaypoint);
    j.at("activeWaypointIndex").get_to(ms.activeWaypointIndex);
    j.at("distanceToWaypoint").get_to(ms.distanceToWaypoint);
}

// Waypoint
void to_json(json& j, const Waypoint& w) {
    j = json{{"position", w.position}, {"depth", w.depth}, {"speed", w.speed}, {"successRadius", w.successRadius}};
}

void from_json(const json& j, Waypoint& w) {
    j.at("position").get_to(w.position);
    j.at("depth").get_to(w.depth);
    j.at("speed").get_to(w.speed);
    j.at("successRadius").get_to(w.successRadius);
}

// WavesStatusReport
void to_json(json& j, const WavesStatusReport& w) {
    j = json{
            {"maneuverControlsState", w.maneuverControlsState},
            {"physicalState", w.physicalState},
            {"missionState", w.missionState},
            {"maneuverGoalsState", w.maneuverGoalsState},
            {"batteryState", w.batteryState},
            {"timePoint", w.timePoint.time_since_epoch().count()},
            {"runTimeSeconds", w.runTimeSeconds}
    };
}

void from_json(const json& j, WavesStatusReport& w) {
    j.at("maneuverControlsState").get_to(w.maneuverControlsState);
    j.at("physicalState").get_to(w.physicalState);
    j.at("missionState").get_to(w.missionState);
    j.at("maneuverGoalsState").get_to(w.maneuverGoalsState);
    j.at("batteryState").get_to(w.batteryState);
    double time_since_epoch = j.at("timePoint").get<double>();
    w.timePoint = TimePoint(std::chrono::duration<double>(time_since_epoch));
    j.at("runTimeSeconds").get_to(w.runTimeSeconds);
}
