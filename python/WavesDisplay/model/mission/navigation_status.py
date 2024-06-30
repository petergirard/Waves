from dataclasses import dataclass


@dataclass
class NavigationStatus:
    distanceToWaypoint: float = 0
    yawGoal: float = 0
    yawError: float = 0
    depthGoal: float = 0
    depthError: float = 0
    speedGoal: float = 0
    speedError: float = 0

    def to_dict(self):
        return {
            'distanceToWaypoint': self.distanceToWaypoint,
            'yawGoal': self.yawGoal,
            'yawError': self.yawError,
            'depthGoal': self.depthGoal,
            'depthError': self.depthError,
            'speedGoal': self.speedGoal,
            'speedError': self.speedError
        }

    @staticmethod
    def from_dict(data):
        return NavigationStatus(**data)