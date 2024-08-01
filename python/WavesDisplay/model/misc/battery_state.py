from dataclasses import dataclass


@dataclass
class BatteryState:
    percentRemaining: float = 0
    wattHoursRemaining: float = 0

    def to_dict(self):
        return {
            'percentRemaining':self.percentRemaining,
            'wattHoursRemaining':self.wattHoursRemaining
        }

    @classmethod
    def from_dict(cls, data):
        return cls(
            percentRemaining=data['percentRemaining'],
            wattHoursRemaining=data['wattHoursRemaining']
        )