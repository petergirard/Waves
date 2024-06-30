from comms.rabbit_publisher import RabbitPublisher

publisher = RabbitPublisher(exchange='vehicle_data', exchange_type='fanout')
try:
    publisher.connect()
    publisher.publish_message(message="Hello, World!")

finally:
    publisher.close_connection()
    print('Connection closed')