from dataclasses import dataclass, field
from command_base import CommandBase
from model.mission.mission import Mission
import datetime

@dataclass
class LoadMissionCommand(CommandBase):
    mission: Mission = field(default_factory=Mission) # mission to load.

    def to_dict(self):
        data = super().to_dict()
        data['mission'] = self.mission
        return data

    @classmethod
    def from_dict(cls, data):
        return cls(
            mission=data['mission'],
            timeIssued=datetime.datetime.fromisoformat(data['timeIssued'])
        )