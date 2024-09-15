from dataclasses import dataclass, field
from typing import Optional

from model.maneuver.maneuver_base import ManeuverBase
from model.base.point3D import Point3D

@dataclass
class DriveToManeuver(ManeuverBase):
    toPosition: Point3D = field(default_factory=Point3D)
    fromPosition: Optional[Point3D] = None
    speed: float = 1.5

    def to_dict(self):
        data = super().to_dict()
        data['toPosition'] = self.toPosition
        data['fromPosition'] = self.fromPosition
        data['speed'] = self.speed
        return data

    @classmethod
    def from_dict(cls, data):
        return cls(**data)