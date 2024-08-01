from dataclasses import dataclass


@dataclass
class ManeuverControlsState:
    elevator: float = 0 # percent (-1 to 1). Affects pitch. Positive trailing edge down.
    rudder: float = 0 # percent (-1 to 1) Affects yaw. Positive trailing edge to port.
    throttle: float = 0 # percent (0 to 1).

    def to_dict(self):
        return {
            'elevator': self.elevator,
            'rudder': self.rudder,
            'throttle': self.throttle
        }

    @classmethod
    def from_dict(cls, data):
        return cls(**data)