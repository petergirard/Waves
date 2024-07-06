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

    @staticmethod
    def from_dict(data):
        return BatteryState(
            percentRemaining=data['percentRemaining'],
            wattHoursRemaining=data['wattHoursRemaining']
        )