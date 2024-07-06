import datetime
import numpy as np
from typing import List

from model.misc.battery_state import BatteryState
from model.report.waves_status_report import WavesStatusReport
from model.base.point2D import Point2D


class DataCache:
    def __init__(self, max_time: datetime.timedelta):
        self.messages: List[WavesStatusReport] = []
        self.max_time = max_time
        self.times = []
        self.elevator = []
        self.rudder = []
        self.throttle = []
        self.speed = []
        self.speed_goal = []
        self.pitch = []
        self.pitch_goal = []
        self.yaw = []
        self.yaw_goal = []
        self.depth = []
        self.depth_goal = []
        self.distance_to_waypoint = []
        self.x_position = []
        self.y_position = []
        self.current_waypoint_index = 0
        self.current_point = Point2D(0, 0)
        self.current_point_goal = Point2D(0, 0)

    def add_message(self, message: WavesStatusReport) -> None:
        self.messages.append(message)
        print(f"added message: {message}")
        self.times.append(message.runTimeSeconds)
        self.elevator.append(message.maneuverControlsState.elevator)
        self.rudder.append(message.maneuverControlsState.rudder)
        self.throttle.append(message.maneuverControlsState.throttle)
        self.speed.append(message.physicalState.velocityVehicleFrame.x)
        self.speed_goal.append(message.maneuverGoalsState.speedGoal)
        self.pitch.append(np.degrees(message.physicalState.attitude.pitch))
        self.pitch_goal.append(np.degrees(message.maneuverControlsState.pitchGoal))
        self.yaw.append(np.degrees(message.physicalState.attitude.yaw))
        self.yaw_goal.append(np.degrees(message.maneuverGoalsState.yawGoal))
        self.depth.append(message.physicalState.position.z)
        self.depth_goal.append(message.maneuverGoalsState.depthGoal)
        self.distance_to_waypoint.append(message.missionState.distanceToWaypoint)
        self.x_position.append(message.physicalState.position.x)
        self.y_position.append(message.physicalState.position.y)
        self.current_waypoint_index = message.missionState.activeWaypointIndex
        self.current_point = message.physicalState.position
        self.current_point_goal = message.missionState.activeWaypoint.position

        
        # remove old messages
        while self.get_max_data_age() > self.max_time:
            self.messages.pop(0)
            self.times.pop(0)
            self.elevator.pop(0)
            self.rudder.pop(0)
            self.throttle.pop(0)
            self.speed.pop(0)
            self.speed_goal.pop(0)
            self.pitch.pop(0)
            self.pitch_goal.pop(0)
            self.yaw.pop(0)
            self.yaw_goal.pop(0)
            self.depth.pop(0)
            self.depth_goal.pop(0)
            self.distance_to_waypoint.pop(0)
            # keep all position data

    def get_max_data_age(self) -> datetime.timedelta:
        if len(self.messages) < 2:
            return datetime.timedelta(0)
        return self.messages[-1].timePoint - self.messages[0].timePoint


