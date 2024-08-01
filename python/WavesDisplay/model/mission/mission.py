from dataclasses import dataclass, field
from typing import List

from model.mission.waypoint import Waypoint


@dataclass
class Mission:
    name: str = ""
    waypoints: List[Waypoint] = field(default_factory=list)

    def to_dict(self):
        return {
            'name': self.name,
            'waypoints': [waypoint.to_dict() for waypoint in self.waypoints]
        }

    @classmethod
    def from_dict(cls, data):
        return cls(
            name=data['name'],
            waypoints=[Waypoint.from_dict(wp) for wp in data['waypoints']]
        )