from dataclasses import dataclass
import math

@dataclass
class Vector2D:
    x: float = 0
    y: float = 0
    magnitude: float = 0

    def __post_init__(self):
        self.magnitude = math.sqrt(self.x ** 2 + self.y ** 2)

    def __add__(self, other):
        return Vector2D(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Vector2D(self.x - other.x, self.y - other.y)

    def to_dict(self):
        return {
            'x': self.x,
            'y': self.y,
            'magnitude': self.magnitude
        }

    @classmethod
    def from_dict(cls, data):
        return cls(**data)