from dataclasses import dataclass
import math

@dataclass
class Vector3D:
    x: float = 0
    y: float = 0
    z: float = 0
    magnitude: float = 0

    def __post_init__(self):
        self.magnitude = math.sqrt(self.x ** 2 + self.y ** 2 + self.z ** 2)

    def __add__(self, other):
        return Vector3D(self.x + other.x, self.y + other.y, self.z + other.z)

    def __sub__(self, other):
        return Vector3D(self.x - other.x, self.y - other.y, self.z - other.z)

    def to_dict(self):
        return {
            'x': self.x,
            'y': self.y,
            'z': self.z,
            'magnitude': self.magnitude
        }

    @staticmethod
    def from_dict(data):
        return Vector3D(**data)