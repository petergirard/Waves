from PyQt6.QtWidgets import QMainWindow, QTabWidget, QWidget
from PyQt6 import QtCore

from comms.data_cache import DataCache
from control.vehicle_controller import VehicleController
from view.real_time_view import RealTimeView
from view.vehicle_control_view import VehicleControlView


class MainWindow(QMainWindow):
    def __init__(self, vehicle_controller: VehicleController, data_cache: DataCache):
        super().__init__()

        self.setWindowTitle('Main Window')
        self.setGeometry(100, 100, 1200, 800)

        # Create the tab widget
        self.tabs = QTabWidget()
        self.setCentralWidget(self.tabs)

        # Add tabs
        self.mission_planning = QWidget()
        self.tabs.addTab(self.mission_planning, 'Mission Planning')

        self.real_time_view = RealTimeView(data_cache)
        self.tabs.addTab(self.real_time_view, 'Real-Time Display')

        self.vehicle_control_view = VehicleControlView(vehicle_controller, data_cache)
        self.tabs.addTab(self.vehicle_control_view, 'Vehicle Control')

        self.timer = QtCore.QTimer()
        self.timer.timeout.connect(self._update)
        self.timer.setInterval(100)

    def run(self) -> None:
        self.show()
        self.real_time_view.show()
        self.vehicle_control_view.show()
        self.timer.start()

    def _update(self) -> None:
        self.real_time_view.update()