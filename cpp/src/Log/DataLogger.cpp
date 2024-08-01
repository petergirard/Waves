//
// Created by Peter on 7/5/2024.
//

#include "DataLogger.h"
#include "../Util/FormatUtils.h"

#include <utility>

DataLogger::DataLogger(std::string fileDirectory_) : headers(getHeaders()), fileDirectory(std::move(fileDirectory_)) {

}


void DataLogger::init() {

}

void DataLogger::log(const WavesStatusReport &message) {

    std::vector<std::string> values(headers.size());

    // Duration
    values.emplace_back(FormatUtils::formatDate(message.timePoint));
    values.emplace_back(FormatUtils::formatTime(message.timePoint));

    // Physical State
    auto ps = message.physicalState;

    values.emplace_back(FormatUtils::doubleToString(ps.position.x, 2));
    values.emplace_back(FormatUtils::doubleToString(ps.position.y, 2));
    values.emplace_back(FormatUtils::doubleToString(ps.position.z, 2));

    // TODO: implement the rest
}


std::vector<std::string> DataLogger::getHeaders() {
    std::vector<std::string> headers;
    int i = 0;

    // Duration
    headers.emplace_back("date");
    headers.emplace_back("date");
    headers.emplace_back("time");

    // Physical State
    headers.emplace_back("position_x_m");
    headers.emplace_back("position_y_m");
    headers.emplace_back("position_z_m");
    headers.emplace_back("velocity_vf_x_ms");
    headers.emplace_back("velocity_vf_y_ms");
    headers.emplace_back("velocity_vf_z_ms");
    headers.emplace_back("velocity_wf_x_ms");
    headers.emplace_back("velocity_wf_y_ms");
    headers.emplace_back("velocity_wf_z_ms");
    headers.emplace_back("roll_deg");
    headers.emplace_back("pitch_deg");
    headers.emplace_back("yaw_deg");
    headers.emplace_back("roll_rate_ds");
    headers.emplace_back("pitch_rate_ds");
    headers.emplace_back("yaw_rate_ds");

    // Maneuver State
    headers.emplace_back("yaw_goal_deg");
    headers.emplace_back("yaw_error_deg");
    headers.emplace_back("depth_goal_m");
    headers.emplace_back("depth_error_m");
    headers.emplace_back("speed_goal_ms");
    headers.emplace_back("speed_error_ms");

    // Maneuver Controls State
    headers.emplace_back("pitch_goal_deg");
    headers.emplace_back("elevator");
    headers.emplace_back("rudder");
    headers.emplace_back("throttle");

    // Mission State
    headers.emplace_back("active_mission_state");
    headers.emplace_back("active_mission");
    headers.emplace_back("active_waypoint");
    headers.emplace_back("distance_to_waypoint_m");

    return headers;
}

