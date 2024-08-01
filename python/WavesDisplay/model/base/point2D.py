from dataclasses import dataclass

@dataclass
class Point2D:
    x: float = 0
    y: float = 0

    def __add__(self, other):
        return Point2D(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Point2D(self.x - other.x, self.y - other.y)

    def to_dict(self):
        return {
            'x': self.x,
            'y': self.y
        }

    @classmethod
    def from_dict(cls, data):
        return cls(**data)