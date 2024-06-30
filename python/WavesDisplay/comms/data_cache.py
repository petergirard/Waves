import datetime
import numpy as np
from typing import List

from comms.waves_status_message import WavesStatusMessage


class DataCache:
    def __init__(self, max_time: datetime.timedelta):
        self.messages: List[WavesStatusMessage] = []
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

    def add_message(self, message: WavesStatusMessage) -> None:
        self.messages.append(message)
        print(f"added message: {message}")
        self.times.append(message.runTimeSeconds)
        self.elevator.append(message.maneuverControls.elevator)
        self.rudder.append(message.maneuverControls.rudder)
        self.throttle.append(message.maneuverControls.throttle)
        self.speed.append(message.maneuverState.velocityVehicleFrame.x)
        self.speed_goal.append(message.navigationStatus.speedGoal)
        self.pitch.append(np.degrees(message.maneuverState.attitude.pitch))
        self.pitch_goal.append(np.degrees(message.maneuverControls.pitchGoal))
        self.yaw.append(np.degrees(message.maneuverState.attitude.yaw))
        self.yaw_goal.append(np.degrees(message.navigationStatus.yawGoal))
        self.depth.append(message.maneuverState.position.z)
        self.depth_goal.append(message.navigationStatus.depthGoal)
        
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

    def get_max_data_age(self) -> datetime.timedelta:
        if len(self.messages) < 2:
            return datetime.timedelta(0)
        return self.messages[-1].timePoint - self.messages[0].timePoint


