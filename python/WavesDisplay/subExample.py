import time
import datetime
import threading

from comms.data_cache import DataCache
from comms.rabbit_subscriber import RabbitSubscriber

import json

from comms.waves_status_message import WavesStatusMessage
from display.real_time_display import RealTimeDisplay
from model.maneuver.maneuver_controls import ManeuverControls

data_cache = DataCache(datetime.timedelta(seconds=10))
display = RealTimeDisplay(data_cache)

def callback(ch, method, properties, body):
    message = WavesStatusMessage.from_json(body)
    data_cache.add_message(message)


def start_consumer():
    subscriber = RabbitSubscriber(queue='hello', exchange='waves_status_message', exchange_type='fanout', routing_key='')
    subscriber.connect()
    subscriber.start_consuming(callback=callback)


# fake_message = WavesStatusMessage(maneuverControls=ManeuverControls(
#     pitchGoal=5, elevator=0, rudder=0, throttle=0
# ))
# data_cache.add_message(fake_message)

rabbitmq_thread = threading.Thread(target=start_consumer, daemon=True)
rabbitmq_thread.start()

display.plot_properties_realtime()