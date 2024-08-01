from dataclasses import dataclass, field

from model.maneuver.maneuver_completion_criteria import ManeuverCompletionCriteria


@dataclass
class ManeuverBase:
    maneuverCompletionCriteria: ManeuverCompletionCriteria = field(default_factory=ManeuverCompletionCriteria)

    def to_dict(self):
        return {
            'maneuverCompletionCriteria': self.maneuverCompletionCriteria,
        }

    @classmethod
    def from_dict(cls, data):
        return cls(**data)