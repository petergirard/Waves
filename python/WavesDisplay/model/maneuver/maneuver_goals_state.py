from dataclasses import dataclass


@dataclass
class ManeuverGoalsState:
    pitchGoal: float = 0
    pitchError: float = 0
    yawGoal: float = 0
    yawError: float = 0
    depthGoal: float = 0
    depthError: float = 0
    speedGoal: float = 0
    speedError: float = 0

    def to_dict(self):
        return {
            'pitchGoal': self.pitchGoal,
            'pitchError': self.pitchError,
            'yawGoal': self.yawGoal,
            'yawError': self.yawError,
            'depthGoal': self.depthGoal,
            'depthError': self.depthError,
            'speedGoal': self.speedGoal,
            'speedError': self.speedError
        }

    @classmethod
    def from_dict(cls, data):
        return cls(**data)