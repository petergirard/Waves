from dataclasses import dataclass
from typing import Generic, TypeVar
from command_base import CommandBase
import datetime

T = TypeVar('T')

@dataclass
class ManeuverCommand(Generic[T], CommandBase):
    maneuver: T

    def to_dict(self):
        data = super().to_dict()
        data['maneuver'] = self.maneuver
        return data

    @classmethod
    def from_dict(cls, data):
        return cls(
            maneuver=data['maneuver'],
            timeIssued=datetime.datetime.fromisoformat(data['timeIssued'])
        )