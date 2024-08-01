from dataclasses import dataclass

from command_base import CommandBase
import datetime

@dataclass
class StopCommand(CommandBase):
    placeholder: str = 'Stop'

    def to_dict(self):
        data = super().to_dict()
        return data

    @classmethod
    def from_dict(cls, data):
        return cls(
            timeIssued=datetime.datetime.fromisoformat(data['timeIssued'])
        )