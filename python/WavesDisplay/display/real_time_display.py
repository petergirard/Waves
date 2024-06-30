import logging
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import time

from comms.data_cache import DataCache

class RealTimeDisplay:
    def __init__(self, data_cache: DataCache):
        self.data_cache = data_cache

    def plot_properties_realtime(self):
        fig, axs = plt.subplots(2, 3, figsize=(18, 10))  # 2 rows, 3 columns

        plt.ion()  # Enable interactive mode
        plt.show()

        logging.info("Started real-time display loop")

        # Plot titles and labels
        axs[0, 0].set_title('Maneuver Controls')
        axs[0, 0].set_ylabel('Percent')
        # axs[0, 0].set_ylim(-1, 1)
        axs[0, 1].set_title('Velocity Vehicle Frame and Speed Goal')
        axs[0, 1].set_ylabel('m/s')
        # axs[0, 1].set_ylim(0, 3)
        axs[0, 2].set_title('Pitch and Pitch Goal')
        axs[0, 2].set_ylabel('Degrees')
        axs[1, 0].set_title('Yaw and Yaw Goal')
        axs[1, 0].set_ylabel('Degrees')
        axs[1, 1].set_title('Depth and Depth Goal')
        axs[1, 1].set_ylabel('Meters')
        axs[1, 2].axis('off')  # Turn off axis for empty subplot

        # Initialize the lines
        lines = {
            'elevator': axs[0, 0].plot([], [], label='Elevator')[0],
            'rudder': axs[0, 0].plot([], [], label='Rudder')[0],
            'throttle': axs[0, 0].plot([], [], label='Throttle')[0],
            'velocity_x': axs[0, 1].plot([], [], label='Velocity X')[0],
            'speed_goal': axs[0, 1].plot([], [], label='Speed Goal')[0],
            'pitch': axs[0, 2].plot([], [], label='Pitch')[0],
            'pitch_goal': axs[0, 2].plot([], [], label='Pitch Goal')[0],
            'yaw': axs[1, 0].plot([], [], label='Yaw')[0],
            'yaw_goal': axs[1, 0].plot([], [], label='Yaw Goal')[0],
            'depth': axs[1, 1].plot([], [], label='Depth')[0],
            'depth_goal': axs[1, 1].plot([], [], label='Depth Goal')[0]
        }

        def init():
            # Set axis limits and add legends
            for ax in axs.flat:
                ax.set_xlim(0, 1)
                ax.set_ylim(0, 1)
                ax.legend()

        def update():
            if not self.data_cache:
                return

            times = self.data_cache.times
            dc = self.data_cache

            # Update data for each line
            lines['elevator'].set_data(times, dc.elevator)
            lines['rudder'].set_data(times, dc.rudder)
            lines['throttle'].set_data(times, dc.throttle)
            lines['velocity_x'].set_data(times, dc.speed)
            lines['speed_goal'].set_data(times, dc.speed_goal)
            lines['pitch'].set_data(times, dc.pitch)
            lines['pitch_goal'].set_data(times, dc.pitch_goal)
            lines['yaw'].set_data(times, dc.yaw)
            lines['yaw_goal'].set_data(times, dc.yaw_goal)
            lines['depth'].set_data(times, dc.depth)
            lines['depth_goal'].set_data(times, dc.depth_goal)

            # Adjust x and y limits for each subplot
            for ax in axs.flat:
                ax.relim()
                ax.autoscale_view()

        # ani = FuncAnimation(fig, update, init_func=init, interval=100)

        # init()
        plt.tight_layout()
        plt.show()

        logging.info("Started real-time display loop")


        while True:
            update()
            plt.pause(0.1)  # Pause briefly to allow the plot to update
            time.sleep(0.1)  # Adjust as needed to balance update rate and performance