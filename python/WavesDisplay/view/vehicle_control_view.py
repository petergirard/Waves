import datetime

from PyQt6.QtWidgets import QWidget, QVBoxLayout, QPushButton

from comms.data_cache import DataCache
from control.vehicle_controller import VehicleController
from model.base.point3D import Point3D
from model.mission.mission import Mission
from model.mission.waypoint import Waypoint


class VehicleControlView(QWidget):
    def __init__(self, vehicle_controller: VehicleController, data_cache: DataCache):
        super().__init__()
        self.vehicle_controller = vehicle_controller
        self.data_cache = data_cache

        layout = QVBoxLayout(self)
        self.button = QPushButton("Load Mission")
        layout.addWidget(self.button)

        self.button.clicked.connect(self._load_mission_clicked)


    def _load_mission_clicked(self) -> None:
        self.vehicle_controller.load_mission(datetime.datetime.now(), self._get_mission())
        self.vehicle_controller.run_mission(datetime.datetime.now(), "test_mission")

    def _get_mission(self) -> Mission:
        wp1 = Waypoint(Point3D(50, 50, 10), 1.5, 10)
        wp2 = Waypoint(Point3D(50, 0, 10), 1.5, 10)
        wp3 = Waypoint(Point3D(0, 50, 10), 1.5, 10)
        wp4 = Waypoint(Point3D(0, 0, 10), 1.5, 10)
        return Mission("test_mission", [wp1, wp2, wp3, wp4])