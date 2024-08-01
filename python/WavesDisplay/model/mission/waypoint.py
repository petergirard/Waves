from dataclasses import dataclass, field

from model.base.point3D import Point3D


@dataclass
class Waypoint:
    position: Point3D = field(default_factory=Point3D)
    speed: float = 0 # meters/sec.
    successRadius: float = 0 # meters. Distance the vehicle must be from the WP before being considered "achieved".

    def to_dict(self):
        return {
            'position': self.position.to_dict(),
            'depth': self.depth,
            'speed': self.speed,
            'successRadius': self.successRadius
        }

    @classmethod
    def from_dict(cls, data):
        return cls(
            position=Point3D.from_dict(data['position']),
            speed=data['speed'],
            successRadius=data['successRadius']
        )