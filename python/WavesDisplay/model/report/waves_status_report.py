from dataclasses import dataclass, asdict, field
import datetime
import json
from typing import Optional

from model.maneuver.maneuver_controls_state import ManeuverControlsState
from model.maneuver.physical_state import PhysicalState
from model.misc.battery_state import BatteryState
from model.mission.mission_execution_state import MissionExecutionState
from model.maneuver.maneuver_goals_state import ManeuverGoalsState

@dataclass
class WavesStatusReport:
    maneuverControlsState: ManeuverControlsState = field(default_factory=ManeuverControlsState)
    physicalState: PhysicalState = field(default_factory=PhysicalState)
    missionExecutionState: MissionExecutionState = field(default_factory=MissionExecutionState)
    maneuverGoalsState: Optional[ManeuverGoalsState] = field(default_factory=ManeuverGoalsState)
    batteryState: BatteryState = field(default_factory=BatteryState)
    timePoint: datetime.datetime = datetime.datetime.fromtimestamp(0)
    runTimeSeconds: float = 0

    def to_dict(self):
        """Convert the instance to a dictionary for JSON serialization."""
        data = asdict(self)
        data['timePoint'] = self.timePoint.isoformat()
        return data

    @classmethod
    def from_dict(cls, data):
        """Create an instance from a dictionary, handling nested deserialization."""
        data['maneuverControlsState'] = ManeuverControlsState.from_dict(data['maneuverControlsState'])
        data['physicalState'] = PhysicalState.from_dict(data['physicalState'])
        data['missionExecutionState'] = MissionExecutionState.from_dict(data['missionExecutionState'])
        if 'maneuverGoalsState' in data:
            data['maneuverGoalsState'] = ManeuverGoalsState.from_dict(data['maneuverGoalsState'])
        data['batteryState'] = BatteryState.from_dict(data['batteryState'])
        data['timePoint'] = datetime.datetime.fromtimestamp(data['timePoint'])
        data['runTimeSeconds'] = float(data['runTimeSeconds'])
        return cls(**data)

    def to_json(self):
        """Convert the instance to JSON."""
        return json.dumps(self.to_dict())

    @classmethod
    def from_json(cls, json_str):
        """Create an instance from a JSON string."""
        data = json.loads(json_str)
        return cls.from_dict(data)