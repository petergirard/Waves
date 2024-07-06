from PyQt6.QtWidgets import QMainWindow, QTabWidget, QWidget
from PyQt6 import QtCore

from comms.data_cache import DataCache
from view.real_time_display import RealTimeDisplay


class MainWindow(QMainWindow):
    def __init__(self, data_cache: DataCache):
        super().__init__()

        self.setWindowTitle('Main Window')
        self.setGeometry(100, 100, 1200, 800)

        # Create the tab widget
        self.tabs = QTabWidget()
        self.setCentralWidget(self.tabs)

        # Add a placeholder tab for mission planning
        self.mission_planning = QWidget()
        self.tabs.addTab(self.mission_planning, 'Mission Planning')

        # Add the RealTimeDisplay tab
        self.real_time_display = RealTimeDisplay(data_cache)
        self.tabs.addTab(self.real_time_display, 'Real-Time Display')

        self.timer = QtCore.QTimer()
        self.timer.timeout.connect(self._update)
        self.timer.setInterval(100)

    def run(self) -> None:
        self.show()
        self.real_time_display.show()
        self.timer.start()

    def _update(self) -> None:
        self.real_time_display.update()