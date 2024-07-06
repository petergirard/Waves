from dataclasses import dataclass, asdict
import datetime
import json

from model.maneuver.maneuver_control_state import ManeuverControlState
from model.maneuver.physical_state import PhysicalState
from model.misc.battery_state import BatteryState
from model.mission.mission_state import MissionState
from model.maneuver.maneuver_goals_state import ManeuverGoalsState


@dataclass
class WavesStatusReport:
    maneuverControlsState: ManeuverControlState #= field(default_factory=ManeuverControls)
    physicalState: PhysicalState #= field(default_factory=ManeuverState)
    missionState: MissionState #= field(default_factory=MissionStatus)
    maneuverGoalsState: ManeuverGoalsState #= field(default_factory=NavigationStatus)
    batteryState: BatteryState
    timePoint: datetime.datetime #= datetime.datetime.fromtimestamp(0)
    runTimeSeconds: float #= 0

    def to_dict(self):
        """Convert the instance to a dictionary for JSON serialization."""
        data = asdict(self)
        data['timePoint'] = self.timePoint.isoformat()
        return data

    @staticmethod
    def from_dict(data):
        """Create an instance from a dictionary, handling nested deserialization."""
        data['maneuverControlsState'] = ManeuverControlState.from_dict(data['maneuverControlsState'])
        data['physicalState'] = PhysicalState.from_dict(data['physicalState'])
        data['missionState'] = MissionState.from_dict(data['missionState'])
        data['maneuverGoalsState'] = ManeuverGoalsState.from_dict(data['maneuverGoalsState'])
        data['batteryState'] = BatteryState.from_dict(data['batteryState'])
        data['timePoint'] = datetime.datetime.fromtimestamp(data['timePoint'])
        data['runTimeSeconds'] = float(data['runTimeSeconds'])
        return WavesStatusReport(**data)

    def to_json(self):
        """Convert the instance to JSON."""
        return json.dumps(self.to_dict())

    @staticmethod
    def from_json(json_str):
        """Create an instance from a JSON string."""
        data = json.loads(json_str)
        return WavesStatusReport.from_dict(data)