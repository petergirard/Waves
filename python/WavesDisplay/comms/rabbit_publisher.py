import pika
from comms.rabbit_client import RabbitClient


class RabbitPublisher(RabbitClient):
    def publish_message(self, message: str, persistent: bool = False):
        if self.channel is None:
            raise Exception("Not connected to RabbitMQ. Call connect() first.")

        properties = None
        if not persistent:
            properties = pika.BasicProperties(delivery_mode=1)
        self.channel.basic_publish(exchange=self.exchange, routing_key=self.routing_key, body=message)
