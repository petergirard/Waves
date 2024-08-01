from dataclasses import dataclass
import datetime
from typing import Optional


@dataclass
class ManeuverCompletionCriteria:
    proximityToGoal: Optional[float] = None # Maneuver is complete when within a certain distance to a location.
    perpendicularToGoal: Optional[bool] = None # Maneuver is complete when vehicle is passed the line that is perpendicular to the drive line and goes through the goal location (only allowed for DriveAlongLineManeuver).
    completionTime: Optional[datetime.datetime] = None # Maneuver is complete after time is reached.
    duration: Optional[datetime.timedelta] = None # Maneuver is complete after running for a certain duration
    depthReached: Optional[float] = None # Maneuver is complete once a depth is reached.

    def to_dict(self):
        return {
            'proximityToGoal': self.proximityToGoal,
            'perpendicularToGoal': self.perpendicularToGoal,
            'completionTime': self.completionTime,
            'duration': self.duration,
            'depthReached': self.depthReached,
        }

    @classmethod
    def from_dict(cls, data):
        return cls(**data)