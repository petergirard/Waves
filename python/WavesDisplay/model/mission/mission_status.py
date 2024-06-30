from dataclasses import dataclass, field
from enum import Enum

from model.mission.mission import Mission
from model.mission.waypoint import Waypoint


class MissionState(Enum):
    Unknown = 0
    Running = 1
    Finished = 2


@dataclass
class MissionStatus:
    state: MissionState = MissionState.Unknown
    activeMission: Mission = field(default_factory=Mission)
    activeWaypoint: Waypoint = field(default_factory=Waypoint)
    activeWaypointIndex: int = 0

    def to_dict(self):
        return {
            'state': self.state.value,
            'activeMission': self.activeMission.to_dict(),
            'activeWaypoint': self.activeWaypoint.to_dict(),
            'activeWaypointIndex': self.activeWaypointIndex
        }

    @staticmethod
    def from_dict(data):
        return MissionStatus(
            state=MissionState(data['state']),
            activeMission=Mission.from_dict(data['activeMission']),
            activeWaypoint=Waypoint.from_dict(data['activeWaypoint']),
            activeWaypointIndex=data['activeWaypointIndex']
        )