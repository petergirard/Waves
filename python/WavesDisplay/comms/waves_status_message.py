from dataclasses import dataclass, field, asdict
import datetime
import json

from model.maneuver.maneuver_controls import ManeuverControls
from model.maneuver.maneuver_state import ManeuverState
from model.mission.mission_status import MissionStatus
from model.mission.navigation_status import NavigationStatus


@dataclass
class WavesStatusMessage:
    maneuverControls: ManeuverControls #= field(default_factory=ManeuverControls)
    maneuverState: ManeuverState #= field(default_factory=ManeuverState)
    missionStatus: MissionStatus #= field(default_factory=MissionStatus)
    navigationStatus: NavigationStatus #= field(default_factory=NavigationStatus)
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
        data['maneuverControls'] = ManeuverControls.from_dict(data['maneuverControls'])
        data['maneuverState'] = ManeuverState.from_dict(data['maneuverState'])
        data['missionStatus'] = MissionStatus.from_dict(data['missionStatus'])
        data['navigationStatus'] = NavigationStatus.from_dict(data['navigationStatus'])
        data['timePoint'] = datetime.datetime.fromtimestamp(data['timePoint'])
        return WavesStatusMessage(**data)

    def to_json(self):
        """Convert the instance to JSON."""
        return json.dumps(self.to_dict())

    @staticmethod
    def from_json(json_str):
        """Create an instance from a JSON string."""
        data = json.loads(json_str)
        return WavesStatusMessage.from_dict(data)