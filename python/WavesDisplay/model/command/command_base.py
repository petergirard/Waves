import json
from dataclasses import dataclass
import datetime


@dataclass
class CommandBase:
    timeIssued: datetime.datetime

    def to_dict(self):
        return {
            'timeIssued': self.timeIssued.isoformat(),
        }

    @classmethod
    def from_dict(cls, data):
        return cls(timeIssued=datetime.datetime.fromisoformat(data['timeIssued']))

    def to_json(self):
        """Convert the instance to JSON."""
        return json.dumps(self.to_dict())

    @classmethod
    def from_json(cls, json_str):
        """Create an instance from a JSON string."""
        data = json.loads(json_str)
        return cls.from_dict(data)