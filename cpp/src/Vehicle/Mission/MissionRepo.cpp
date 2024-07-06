//
// Created by Peter on 7/6/2024.
//

#include "MissionRepo.h"

void MissionRepo::loadMission(const Mission &mission) {
    repo[mission.name] = mission;
}

void MissionRepo::clearMissions() {
    repo.clear();
}

std::optional<Mission> MissionRepo::getMission(const std::string &missionName) {
    if (repo.contains(missionName)){
        return repo[missionName];
    }
    else{
        return std::nullopt;
    }
}

std::vector<Mission> MissionRepo::getLoadedMissions() {
    std::vector<Mission> missions;
    missions.reserve(repo.size());
    for(const auto& pair : repo)
        missions.push_back(pair.second);
    return missions;
}
