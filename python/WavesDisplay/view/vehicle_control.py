import pyqtgraph as pg
from PyQt6.QtWidgets import QGridLayout, QWidget, QVBoxLayout, QLabel

from comms.data_cache import DataCache


class VehicleControl(QWidget):
    def __init__(self, data_cache: DataCache):
        super().__init__()
        self.data_cache = data_cache

        # Create a main layout
        layout = QVBoxLayout(self)

        # Create a widget for information view
        status_widget = QWidget()
        status_layout = QVBoxLayout(status_widget)

        # Add QLabel for displaying information
        self.status_label = QLabel()
        self.status_label.setStyleSheet("background-color: black; padding: 10px;")
        status_layout.addWidget(self.status_label)

        layout.addWidget(status_widget)

    def update(self):
        # TODO: Implement
        return

    def _update_status(self):
        # TODO: Implement
        return