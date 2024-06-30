from dataclasses import dataclass

@dataclass
class Orientation:
    pitch: float = 0
    roll: float = 0
    yaw: float = 0

    def to_dict(self):
        return {
            'pitch': self.pitch,
            'roll': self.roll,
            'yaw': self.yaw
        }

    @staticmethod
    def from_dict(data):
        return Orientation(**data)