from dataclasses import dataclass


@dataclass
class ManeuverControlState:
    pitchGoal: float = 0 # radians
    elevator: float = 0 # percent (-1 to 1). Affects pitch. Positive trailing edge down.
    rudder: float = 0 # percent (-1 to 1) Affects yaw. Positive trailing edge to port.
    throttle: float = 0 # percent (0 to 1).

    def to_dict(self):
        return {
            'pitchGoal': self.pitchGoal,
            'elevator': self.elevator,
            'rudder': self.rudder,
            'throttle': self.throttle
        }

    @staticmethod
    def from_dict(data):
        return ManeuverControlState(**data)