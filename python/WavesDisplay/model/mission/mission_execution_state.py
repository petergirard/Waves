from dataclasses import dataclass, field
from enum import Enum

from model.mission.mission import Mission
from model.mission.waypoint import Waypoint


class ActiveMissionState(Enum):
    Unknown = 0
    Running = 1
    Finished = 2


@dataclass
class MissionExecutionState:
    activeMissionState: ActiveMissionState = ActiveMissionState.Unknown
    activeMission: Mission = field(default_factory=Mission)
    activeWaypoint: Waypoint = field(default_factory=Waypoint)
    activeWaypointIndex: int = 0

    def to_dict(self):
        return {
            'activeMissionState': self.activeMissionState.value,
            'activeMission': self.activeMission.to_dict(),
            'activeWaypoint': self.activeWaypoint.to_dict(),
            'activeWaypointIndex': self.activeWaypointIndex,
            'distanceToWaypoint': self.distanceToWaypoint
        }

    @classmethod
    def from_dict(cls, data):
        return cls(
            activeMissionState=ActiveMissionState(data['activeMissionState']),
            activeMission=Mission.from_dict(data['activeMission']),
            activeWaypoint=Waypoint.from_dict(data['activeWaypoint']),
            activeWaypointIndex=data['activeWaypointIndex'],
        )