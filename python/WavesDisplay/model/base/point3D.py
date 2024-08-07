from dataclasses import dataclass

@dataclass
class Point3D:
    x: float = 0
    y: float = 0
    z: float = 0

    def __add__(self, other):
        return Point3D(self.x + other.x, self.y + other.y, self.z + other.z)

    def __sub__(self, other):
        return Point3D(self.x - other.x, self.y - other.y, self.z - other.z)

    def to_dict(self):
        return {
            'x': self.x,
            'y': self.y,
            'z': self.z
        }

    @classmethod
    def from_dict(cls, data):
        return cls(**data)