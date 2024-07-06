import datetime
import threading
import sys
from PyQt6.QtWidgets import QApplication
from comms.data_cache import DataCache
from comms.rabbit_subscriber import RabbitSubscriber
from model.report.waves_status_report import WavesStatusReport
from view.main_window import  MainWindow


if __name__ == '__main__':
    app = QApplication(sys.argv)
    data_cache = DataCache(datetime.timedelta(seconds=10))
    main_window = MainWindow(data_cache)

    # Load the stylesheet
    with open('view/style.qss', 'r') as file:
        app.setStyleSheet(file.read())

    def callback(ch, method, properties, body):
        message = WavesStatusReport.from_json(body)
        data_cache.add_message(message)


    def start_consumer():
        subscriber = RabbitSubscriber(queue='hello', exchange='waves_status_message', exchange_type='fanout',
                                      routing_key='')
        subscriber.connect()
        subscriber.start_consuming(callback=callback)


    # fake_message = WavesStatusMessage(maneuverControls=ManeuverControls(
    #     pitchGoal=5, elevator=0, rudder=0, throttle=0
    # ))
    # data_cache.add_message(fake_message)

    rabbitmq_thread = threading.Thread(target=start_consumer, daemon=True)
    rabbitmq_thread.start()

    main_window.run()
    sys.exit(app.exec())