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
    j = json{{"elevator", m.elevator}, {"rudder", m.rudder}, {"throttle", m.throttle}};
}

void from_json(const json& j, ManeuverControlsState& m) {
    j.at("elevator").get_to(m.elevator);
    j.at("rudder").get_to(m.rudder);
    j.at("throttle").get_to(m.throttle);
}

// ManeuverGoalsState
void to_json(json& j, const ManeuverGoalsState& ns) {
    j = json{
            {"pitchGoal", ns.pitchGoal},
            {"pitchError", ns.pitchError},
            {"yawGoal", ns.yawGoal},
            {"yawError", ns.yawError},
            {"depthGoal", ns.depthGoal},
            {"depthError", ns.depthError},
            {"speedGoal", ns.speedGoal},
            {"speedError", ns.speedError}
    };
}

void from_json(const json& j, ManeuverGoalsState& ns) {
    j.at("pitchGoal").get_to(ns.pitchGoal);
    j.at("pitchError").get_to(ns.pitchError);
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

// MissionExecutionState
void to_json(json& j, const MissionExecutionState& ms) {
    j = json{
            {"activeMissionState", ms.activeMissionState},
            {"activeMission", ms.activeMission},
            {"activeWaypoint", ms.activeWaypoint},
            {"activeWaypointIndex", ms.activeWaypointIndex}
    };
}

void from_json(const json& j, MissionExecutionState& ms) {
    j.at("activeMissionState").get_to(ms.activeMissionState);
    j.at("activeMission").get_to(ms.activeMission);
    j.at("activeWaypoint").get_to(ms.activeWaypoint);
    j.at("activeWaypointIndex").get_to(ms.activeWaypointIndex);
}

// Waypoint
void to_json(json& j, const Waypoint& w) {
    j = json{{"position", w.position}, {"speed", w.speed}, {"successRadius", w.successRadius}};
}

void from_json(const json& j, Waypoint& w) {
    j.at("position").get_to(w.position);
    j.at("speed").get_to(w.speed);
    j.at("successRadius").get_to(w.successRadius);
}

// WavesStatusReport
void to_json(json& j, const WavesStatusReport& w) {
    j = json{
            {"maneuverControlsState", w.maneuverControlsState},
            {"physicalState", w.physicalState},
            {"missionExecutionState", w.missionExecutionState},
            {"batteryState", w.batteryState},
            {"timePoint", w.timePoint.time_since_epoch().count()},
            {"runTimeSeconds", w.runTimeSeconds}
    };

    if (w.maneuverGoalsState.has_value()){
        j["maneuverGoalsState"] = w.maneuverGoalsState.value();
    }
}

void from_json(const json& j, WavesStatusReport& w) {
    j.at("maneuverControlsState").get_to(w.maneuverControlsState);
    j.at("physicalState").get_to(w.physicalState);
    j.at("missionExecutionState").get_to(w.missionExecutionState);
    j.at("batteryState").get_to(w.batteryState);
    double time_since_epoch = j.at("timePoint").get<double>();
    w.timePoint = TimePoint(std::chrono::duration<double>(time_since_epoch));
    j.at("runTimeSeconds").get_to(w.runTimeSeconds);

    if (j.contains("maneuverGoalsState")){
        w.maneuverGoalsState = j["maneuverGoalsState"];
    }
    else{
        w.maneuverGoalsState = std::nullopt;
    }
}


// MANEUVERS
// ManeuverCompletionCriteria
void to_json(json& j, const ManeuverCompletionCriteria& criteria) {
    j = json::object();

    // Check if value exists before adding to json
    if (criteria.proximityToGoal.has_value()) {
        j["proximityToGoal"] = criteria.proximityToGoal.value();
    }

    if (criteria.perpendicularToGoal.has_value()) {
        j["perpendicularToGoal"] = criteria.perpendicularToGoal.value();
    }

    // Use appropriate serialization for TimePoint
    if (criteria.completionTime.has_value()) {
        j["completionTime"] = criteria.completionTime->time_since_epoch().count();  // Assuming TimePoint has to_json implemented
    }

    // Use appropriate serialization for std::chrono::duration
    if (criteria.duration.has_value()) {
        j["duration"] = criteria.duration.value().count();  // Assuming duration has count() method
    }

    if (criteria.depthReached.has_value()) {
        j["depthReached"] = criteria.depthReached.value();
    }
}

void from_json(const json& j, ManeuverCompletionCriteria& criteria) {
    // Check if key exists before accessing
    if (j.contains("proximityToGoal")) {
        criteria.proximityToGoal = j["proximityToGoal"];
    }
    else {
        criteria.proximityToGoal = std::nullopt;
    }

    if (j.contains("perpendicularToGoal")) {
        criteria.perpendicularToGoal = j["perpendicularToGoal"];
    }
    else {
        criteria.perpendicularToGoal = std::nullopt;
    }

    // Use appropriate deserialization for TimePoint
    if (j.contains("completionTime")) {
        double time_since_epoch = j.at("completionTime").get<double>();
        criteria.completionTime = TimePoint(std::chrono::duration<double>(time_since_epoch));
    }
    else {
        criteria.completionTime = std::nullopt;
    }

    // Use appropriate deserialization for std::chrono::duration
    if (j.contains("duration")) {
        criteria.duration = std::chrono::duration<double>(j["duration"]);  // Assuming conversion from count
    }
    else {
        criteria.duration = std::nullopt;
    }

    if (j.contains("depthReached")) {
        criteria.depthReached = j["depthReached"];
    }
    else {
        criteria.depthReached = std::nullopt;
    }
}

// ManeuverBase
void to_json(json& j, const ManeuverBase& maneuver) {
    j["completionCriteria"] = maneuver.completionCriteria;
}

void from_json(const json& j, ManeuverBase& maneuver) {
    j.at("completionCriteria").get_to(maneuver.completionCriteria);
}

// DriveToManeuver
void to_json(json& j, const DriveToManeuver& maneuver) {
    to_json(j, static_cast<const ManeuverBase&>(maneuver));

    j["toPosition"] = maneuver.toPosition;
    if (maneuver.fromPosition.has_value()) {
        j["fromPosition"] = maneuver.fromPosition.value();
    }
    j["speed"] = maneuver.speed;
}

void from_json(const json& j, DriveToManeuver& maneuver) {
    from_json(j, static_cast<ManeuverBase&>(maneuver));
    j.at("toPosition").get_to(maneuver.toPosition);
    if (j.contains("fromPosition")) {
        maneuver.fromPosition = j["fromPosition"];
    } else {
        maneuver.fromPosition = std::nullopt;
    }
    j.at("speed").get_to(maneuver.speed);
}

// ParkManeuver
void to_json(json& j, const ParkManeuver& maneuver) {
    to_json(j, static_cast<const ManeuverBase&>(maneuver));

    j["parkLocation"] = maneuver.parkLocation;
    j["parkSpeed"] = maneuver.parkSpeed;
    j["parkRadius"] = maneuver.parkRadius;
    if (maneuver.transitFromLocation.has_value()) {
        j["transitFromLocation"] = maneuver.transitFromLocation.value();
    }
    j["transitDepth"] = maneuver.transitDepth;
    j["transitSpeed"] = maneuver.transitSpeed;
}


void from_json(const json& j, ParkManeuver& maneuver) {
    from_json(j, static_cast<ManeuverBase&>(maneuver));

    j.at("parkLocation").get_to(maneuver.parkLocation);
    j.at("parkSpeed").get_to(maneuver.parkSpeed);
    j.at("parkRadius").get_to(maneuver.parkRadius);
    if (j.contains("transitFromLocation")) {
        maneuver.transitFromLocation = j["transitFromLocation"];
    }
    else{
        maneuver.transitFromLocation = std::nullopt;
    }
    j.at("transitDepth").get_to(maneuver.transitDepth);
    j.at("transitSpeed").get_to(maneuver.transitSpeed);
}

void to_json(json& j, const PrimitiveManeuver& maneuver){
    to_json(j, static_cast<const ManeuverBase&>(maneuver));
    j["controlsState"] = maneuver.controlsState;
}

void from_json(const json& j, PrimitiveManeuver& maneuver){
    from_json(j, static_cast<ManeuverBase&>(maneuver));
    j.at("controlsState").get_to(maneuver.controlsState);
}


// COMMANDS

// LoadMissionCommand
void to_json(json& j, const LoadMissionCommand& cmd) {
    j = json{
            {"mission", cmd.mission},
            {"timeIssued", cmd.timeIssued.time_since_epoch().count()}
    };
}

void from_json(const json& j, LoadMissionCommand& cmd) {
    j.at("mission").get_to(cmd.mission);
    double time_since_epoch = j.at("timeIssued").get<double>();
    cmd.timeIssued = TimePoint(std::chrono::duration<double>(time_since_epoch));
}

// RunMissionCommand
void to_json(json& j, const RunMissionCommand& cmd) {
    j = json{
            {"missionName", cmd.missionName},
            {"timeIssue", cmd.timeIssued.time_since_epoch().count()}
    };
}

void from_json(const json& j, RunMissionCommand& cmd) {
    j.at("missionName").get_to(cmd.missionName);
    double time_since_epoch = j.at("timeIssue").get<double>();
    cmd.timeIssued = TimePoint(std::chrono::duration<double>(time_since_epoch));
}

// StopCommand
void to_json(json& j, const StopCommand& cmd) {
    j = json{
            {"timeIssue", cmd.timeIssued.time_since_epoch().count()}
    };
}

void from_json(const json& j, StopCommand& cmd) {
    double time_since_epoch = j.at("timeIssue").get<double>();
    cmd.timeIssued = TimePoint(std::chrono::duration<double>(time_since_epoch));
}

// DriveToManeuverCommand
void to_json(json& j, const ManeuverCommand<DriveToManeuver>& cmd){
    j = json{
            {"timeIssue", cmd.timeIssued.time_since_epoch().count()},
            {"maneuver", cmd.maneuver}
    };
}

void from_json(const json& j, ManeuverCommand<DriveToManeuver>& cmd){
    j.at("maneuver").get_to(cmd.maneuver);
    double time_since_epoch = j.at("timeIssue").get<double>();
    cmd.timeIssued = TimePoint(std::chrono::duration<double>(time_since_epoch));
}

// ParkManeuverCommand
void to_json(json& j, const ManeuverCommand<ParkManeuver>& cmd){
    j = json{
            {"timeIssue", cmd.timeIssued.time_since_epoch().count()},
            {"maneuver", cmd.maneuver}
    };
}

void from_json(const json& j, ManeuverCommand<ParkManeuver>& cmd){
    j.at("maneuver").get_to(cmd.maneuver);
    double time_since_epoch = j.at("timeIssue").get<double>();
    cmd.timeIssued = TimePoint(std::chrono::duration<double>(time_since_epoch));
}

// PrimitiveManeuverCommand
void to_json(json& j, const ManeuverCommand<PrimitiveManeuver>& cmd){
    j = json{
            {"timeIssue", cmd.timeIssued.time_since_epoch().count()},
            {"maneuver", cmd.maneuver}
    };
}

void from_json(const json& j, ManeuverCommand<PrimitiveManeuver>& cmd){
    j.at("maneuver").get_to(cmd.maneuver);
    double time_since_epoch = j.at("timeIssue").get<double>();
    cmd.timeIssued = TimePoint(std::chrono::duration<double>(time_since_epoch));
}