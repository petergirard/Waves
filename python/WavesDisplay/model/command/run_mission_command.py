from dataclasses import dataclass
import datetime

from model.command.command_base import CommandBase

@dataclass
class RunMissionCommand(CommandBase):
    missionName: str

    def to_dict(self):
        data = super().to_dict()
        data['missionName'] = self.missionName
        return data

    @classmethod
    def from_dict(cls, data):
        return cls(
            missionName=data['missionName'],
            timeIssued=datetime.datetime.fromisoformat(data['timeIssued'])
        )