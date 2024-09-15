from comms.comms_factory import CommsFactory
from model.command.load_mission_command import LoadMissionCommand
from model.command.maneuver_command import ManeuverCommand
from model.command.run_mission_command import RunMissionCommand
from model.command.stop_command import StopCommand
from model.maneuver.drive_to_maneuver import DriveToManeuver
from model.maneuver.park_maneuver import ParkManeuver
from model.maneuver.primitive_maneuver import PrimitiveManeuver
from model.mission.mission import Mission
import datetime

class VehicleController:

    def __init__(self, comms_factory: CommsFactory):
        self._load_mission_pub = comms_factory.get_publisher("load_mission_command")
        self._run_mission_pub = comms_factory.get_publisher("run_mission_command")
        self._stop_pub = comms_factory.get_publisher("stop_command")
        self._drive_to_pub = comms_factory.get_publisher("drive_to_maneuver_command")
        self._park_pub = comms_factory.get_publisher("park_maneuver_command")
        self._primitive_pub = comms_factory.get_publisher("primitive_maneuver_command")

    def load_mission(self, time: datetime.datetime, mission: Mission) -> None:
        command = LoadMissionCommand(time, mission)
        self._load_mission_pub.publish_message(command.to_json())

    def run_mission(self, time: datetime.datetime, mission_name:str) -> None:
        command = RunMissionCommand(time, mission_name)
        self._run_mission_pub.publish_message(command.to_json())

    def stop(self, time: datetime.datetime) -> None:
        command = StopCommand(time)
        self._stop_pub.publish_message(command.to_json())

    def drive_to(self, time: datetime.datetime, maneuver: DriveToManeuver) -> None:
        command = ManeuverCommand(time, maneuver)
        self._drive_to_pub.publish_message(command.to_json())

    def park(self, time: datetime.datetime, maneuver: ParkManeuver) -> None:
        command = ManeuverCommand(time, maneuver)
        self._park_pub.publish_message(command.to_json())

    def primitive(self, time: datetime.datetime, maneuver: PrimitiveManeuver) -> None:
        command = ManeuverCommand(time, maneuver)
        self._primitive_pub.publish_message(command.to_json())