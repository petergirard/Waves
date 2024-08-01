from dataclasses import dataclass, field

from model.maneuver.maneuver_base import ManeuverBase
from model.maneuver.maneuver_controls_state import ManeuverControlsState


@dataclass
class PrimitiveManeuver(ManeuverBase):
    controlsState: ManeuverControlsState = field(default_factory=ManeuverControlsState)

    def to_dict(self):
        data = super().to_dict()
        data['controlsState'] = self.controlsState
        return data

    @classmethod
    def from_dict(cls, data):
        return cls(**data)