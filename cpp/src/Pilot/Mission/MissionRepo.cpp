//
// Created by Peter on 7/6/2024.
//

#include "MissionRepo.h"

void MissionRepo::loadMission(Mission&& mission) {
    _missions.emplace(mission.name, std::move(mission));
}

void MissionRepo::clearMissions() {
    _missions.clear();
}

std::optional<Mission> MissionRepo::getMission(const std::string &missionName) {
    if (_missions.contains(missionName)){
        return _missions[missionName];
    }
    else{
        return std::nullopt;
    }
}

std::vector<Mission> MissionRepo::getLoadedMissions() {
    std::vector<Mission> missions;
    missions.reserve(missions.size());
    for(const auto& pair : _missions)
        missions.push_back(pair.second);
    return missions;
}
