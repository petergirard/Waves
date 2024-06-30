from dataclasses import dataclass, field

from model.base.point2D import Point2D


@dataclass
class Waypoint:
    position: Point2D = field(default_factory=Point2D)
    depth: float = 0 # meters. Positive down. Relative to surface.
    speed: float = 0 # meters/sec.
    successRadius: float = 0 # meters. Distance the vehicle must be from the WP before being considered "achieved".

    def to_dict(self):
        return {
            'position': self.position.to_dict(),
            'depth': self.depth,
            'speed': self.speed,
            'successRadius': self.successRadius
        }

    @staticmethod
    def from_dict(data):
        return Waypoint(
            position=Point2D.from_dict(data['position']),
            depth=data['depth'],
            speed=data['speed'],
            successRadius=data['successRadius']
        )