import pyqtgraph as pg
from PyQt6.QtWidgets import QGridLayout, QWidget, QVBoxLayout, QLabel

from comms.data_cache import DataCache
from model.misc.battery_state import BatteryState


class RealTimeView(QWidget):
    def __init__(self, data_cache: DataCache):
        super().__init__()
        self.data_cache = data_cache

        # Create a main layout
        layout = QVBoxLayout(self)

        # Create a widget for plots
        plots_widget = QWidget()
        plot_layout = QGridLayout(plots_widget)

        # Create plots
        self.plots = {
            'maneuver_controls': pg.PlotWidget(title='Maneuver Controls'),
            'velocity_and_speed': pg.PlotWidget(title='Velocity and Speed Goal'),
            'pitch_and_pitch_goal': pg.PlotWidget(title='Pitch and Pitch Goal'),
            'yaw_and_yaw_goal': pg.PlotWidget(title='Yaw and Yaw Goal'),
            'depth_and_depth_goal': pg.PlotWidget(title='Depth and Depth Goal'),
            'position': pg.PlotWidget(title='Position')
        }

        # Add plots to layout
        plot_layout.addWidget(self.plots['maneuver_controls'], 0, 0)
        plot_layout.addWidget(self.plots['velocity_and_speed'], 0, 1)
        plot_layout.addWidget(self.plots['pitch_and_pitch_goal'], 0, 2)
        plot_layout.addWidget(self.plots['yaw_and_yaw_goal'], 1, 0)
        plot_layout.addWidget(self.plots['depth_and_depth_goal'], 1, 1)
        plot_layout.addWidget(self.plots['position'], 1, 2)

        # Set minimum y-axis range
        self.plots['maneuver_controls'].getViewBox().setLimits(minYRange=2)
        self.plots['velocity_and_speed'].getViewBox().setLimits(minYRange=3)
        self.plots['pitch_and_pitch_goal'].getViewBox().setLimits(minYRange=10)
        self.plots['yaw_and_yaw_goal'].getViewBox().setLimits(minYRange=10)
        self.plots['depth_and_depth_goal'].getViewBox().setLimits(minYRange=5)

        # Initialize curves
        self.curves = {
            'elevator': self.plots['maneuver_controls'].plot(pen='r', name='Elevator'),
            'rudder': self.plots['maneuver_controls'].plot(pen='g', name='Rudder'),
            'throttle': self.plots['maneuver_controls'].plot(pen='b', name='Throttle'),
            'velocity_x': self.plots['velocity_and_speed'].plot(pen='r', name='Velocity X'),
            'speed_goal': self.plots['velocity_and_speed'].plot(pen='g', name='Speed Goal'),
            'pitch': self.plots['pitch_and_pitch_goal'].plot(pen='r', name='Pitch'),
            'pitch_goal': self.plots['pitch_and_pitch_goal'].plot(pen='g', name='Pitch Goal'),
            'yaw': self.plots['yaw_and_yaw_goal'].plot(pen='r', name='Yaw'),
            'yaw_goal': self.plots['yaw_and_yaw_goal'].plot(pen='g', name='Yaw Goal'),
            'depth': self.plots['depth_and_depth_goal'].plot(pen='r', name='Depth'),
            'depth_goal': self.plots['depth_and_depth_goal'].plot(pen='g', name='Depth Goal'),
        }

        # Add scatter plot for xy position
        self.scatter = pg.ScatterPlotItem(pen=None, symbol='o', size=5, brush='b')
        self.plots['position'].addItem(self.scatter)
        self.plots['position'].getViewBox().setAspectLocked(True)

        # Add arrow for current position and direction
        self.arrow = pg.ArrowItem(angle=0, headLen=20, brush='r')
        self.plots['position'].addItem(self.arrow)

        # Add legends to the plots with white background and black border
        for plot in self.plots.values():
            legend = pg.LegendItem(offset=(30, 10))
            legend.setParentItem(plot.graphicsItem())
            for item in plot.listDataItems():
                legend.addItem(item, item.name())

        layout.addWidget(plots_widget)

        # Create a widget for information view
        info_widget = QWidget()
        info_layout = QVBoxLayout(info_widget)

        # Add QLabel for displaying information
        self.info_label = QLabel()
        self.info_label.setStyleSheet("background-color: black; padding: 10px;")
        info_layout.addWidget(self.info_label)

        layout.addWidget(info_widget)

        # Set initial text content
        self._update_text()

    def update(self):
        self._update_plots()
        self._update_text()

    def _update_plots(self):
        times = self.data_cache.times
        dc = self.data_cache

        # Update curves with new data
        self.curves['elevator'].setData(times, dc.elevator)
        self.curves['rudder'].setData(times, dc.rudder)
        self.curves['throttle'].setData(times, dc.throttle)
        self.curves['velocity_x'].setData(times, dc.speed)
        self.curves['speed_goal'].setData(times, dc.speed_goal)
        self.curves['pitch'].setData(times, dc.pitch)
        self.curves['pitch_goal'].setData(times, dc.pitch_goal)
        self.curves['yaw'].setData(times, dc.yaw)
        self.curves['yaw_goal'].setData(times, dc.yaw_goal)
        self.curves['depth'].setData(times, dc.depth)
        self.curves['depth_goal'].setData(times, dc.depth_goal)

        # Update scatter plot for xy position. World frame is NED. Need to invert x/y to view on ENU graph.
        with dc.lock: # lock to prevent data lengths from being different lengths.
            self.scatter.setData(dc.y_position, dc.x_position)

        # Update arrow for current position and direction
        if len(dc.x_position) > 0 and len(dc.y_position) > 0 and len(dc.yaw) > 0:
            current_x = dc.x_position[-1]
            current_y = dc.y_position[-1]
            current_yaw = dc.yaw[-1] + 90
            # print(current_yaw)
            self.arrow.setPos(current_y, current_x)
            self.arrow.setStyle(angle=current_yaw)

        self._update_text()

    def _update_text(self):
        dc = self.data_cache

        messages = dc.messages
        speed = dc.speed[-1] if messages else 0
        pitch = dc.pitch[-1] if messages else 0
        yaw = dc.yaw[-1] if messages else 0
        depth = dc.depth[-1] if messages else 0
        battery_state = dc.messages[-1].batteryState if messages else BatteryState()

        # Update text below each plot
        dc = self.data_cache
        info_text = (
            f"Current speed: {speed:.2f} m/s\n"
            f"Current pitch: {pitch:.2f} degrees\n"
            f"Current yaw: {yaw:.2f} degrees\n"
            f"Current depth: {depth:.2f} m\n"
            f"Current waypoint index: {dc.current_waypoint_index}\n"
            f"Current position: {dc.current_point}\n"
            f"Current position goal: {dc.current_point_goal}\n"
            f"Current battery state: {battery_state}"
        )
        self.info_label.setText(info_text)