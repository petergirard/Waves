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

// ManeuverControls
void to_json(json& j, const ManeuverControls& m) {
    j = json{{"pitchGoal", m.pitchGoal}, {"elevator", m.elevator}, {"rudder", m.rudder}, {"throttle", m.throttle}};
}

void from_json(const json& j, ManeuverControls& m) {
    j.at("pitchGoal").get_to(m.pitchGoal);
    j.at("elevator").get_to(m.elevator);
    j.at("rudder").get_to(m.rudder);
    j.at("throttle").get_to(m.throttle);
}

// ManeuverState
void to_json(json& j, const ManeuverState& m) {
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

void from_json(const json& j, ManeuverState& m) {
    j.at("position").get_to(m.position);
    j.at("velocityWorldFrame").get_to(m.velocityWorldFrame);
    j.at("accelerationWorldFrame").get_to(m.accelerationWorldFrame);
    j.at("velocityVehicleFrame").get_to(m.velocityVehicleFrame);
    j.at("accelerationVehicleFrame").get_to(m.accelerationVehicleFrame);
    j.at("attitude").get_to(m.attitude);
    j.at("attitudeVelocity").get_to(m.attitudeVelocity);
    j.at("attitudeAcceleration").get_to(m.attitudeAcceleration);
}

// Mission
void to_json(json& j, const Mission& m) {
    j = json{{"name", m.name}, {"waypoints", m.waypoints}};
}

void from_json(const json& j, Mission& m) {
    j.at("name").get_to(m.name);
    j.at("waypoints").get_to(m.waypoints);
}

// MissionStatus
void to_json(json& j, const MissionStatus& ms) {
    j = json{
            {"state", ms.state},
            {"activeMission", ms.activeMission},
            {"activeWaypoint", ms.activeWaypoint},
            {"activeWaypointIndex", ms.activeWaypointIndex}
    };
}

void from_json(const json& j, MissionStatus& ms) {
    j.at("state").get_to(ms.state);
    j.at("activeMission").get_to(ms.activeMission);
    j.at("activeWaypoint").get_to(ms.activeWaypoint);
    j.at("activeWaypointIndex").get_to(ms.activeWaypointIndex);
}

// NavigationStatus
void to_json(json& j, const NavigationStatus& ns) {
    j = json{
            {"distanceToWaypoint", ns.distanceToWaypoint},
            {"yawGoal", ns.yawGoal},
            {"yawError", ns.yawError},
            {"depthGoal", ns.depthGoal},
            {"depthError", ns.depthError},
            {"speedGoal", ns.speedGoal},
            {"speedError", ns.speedError}
    };
}

void from_json(const json& j, NavigationStatus& ns) {
    j.at("distanceToWaypoint").get_to(ns.distanceToWaypoint);
    j.at("yawGoal").get_to(ns.yawGoal);
    j.at("yawError").get_to(ns.yawError);
    j.at("depthGoal").get_to(ns.depthGoal);
    j.at("depthError").get_to(ns.depthError);
    j.at("speedGoal").get_to(ns.speedGoal);
    j.at("speedError").get_to(ns.speedError);
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

// WavesStatusMessage
void to_json(json& j, const WavesStatusMessage& w) {
    j = json{
            {"maneuverControls", w.maneuverControls},
            {"maneuverState", w.maneuverState},
            {"missionStatus", w.missionStatus},
            {"navigationStatus", w.navigationStatus},
            {"timePoint", w.timePoint.time_since_epoch().count()},
            {"runTimeSeconds", w.runTimeSeconds}
    };
}

void from_json(const json& j, WavesStatusMessage& w) {
    j.at("maneuverControls").get_to(w.maneuverControls);
    j.at("maneuverState").get_to(w.maneuverState);
    j.at("missionStatus").get_to(w.missionStatus);
    j.at("navigationStatus").get_to(w.navigationStatus);
    double time_since_epoch = j.at("timePoint").get<double>();
    w.timePoint = TimePoint(std::chrono::duration<double>(time_since_epoch));
    j.at("runTimeSeconds").get_to(w.runTimeSeconds);
}

