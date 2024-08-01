from dataclasses import dataclass, field
from typing import Optional

from model.base.point3D import Point3D
from model.maneuver.maneuver_base import ManeuverBase


@dataclass
class ParkManeuver(ManeuverBase):
    parkLocation: Point3D = field(default_factory=Point3D) # center of park location
    parkSpeed: float = 1.5 # speed vehicle should drive while parking in m/s
    parkRadius: float = 10 # radius of parking circle in meters
    transitFromLocation: Optional[Point3D] = None # The location the vehicle is transiting from
    transitDepth: float = 0 # The depth the vehicle should drive at while transiting to the park position.
    transitSpeed: float = 1.5 # The speed the vehicle should drive at while transiting to the park position.


    def to_dict(self):
        data = super().to_dict()
        data['parkLocation'] = self.parkLocation
        data['parkSpeed'] = self.parkSpeed
        data['parkRadius'] = self.parkRadius
        data['transitFromLocation'] = self.transitFromLocation
        data['transitDepth'] = self.transitDepth
        data['transitSpeed'] = self.transitSpeed
        return data

    @classmethod
    def from_dict(cls, data):
        return cls(**data)