//
// Created by Peter on 7/6/2024.
//

#ifndef WAVES_MISSIONREPO_H
#define WAVES_MISSIONREPO_H


#include <map>
#include <optional>
#include "../../Model/Mission/Mission.h"

class MissionRepo {
public:
    MissionRepo() = default;

    void loadMission(const Mission& mission);
    void clearMissions();
    std::optional<Mission> getMission(const std::string& missionName);
    std::vector<Mission> getLoadedMissions();

private:
    std::map<std::string, Mission> repo;
};


#endif //WAVES_MISSIONREPO_H
