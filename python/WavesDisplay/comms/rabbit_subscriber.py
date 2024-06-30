from comms.rabbit_client import RabbitClient


class RabbitSubscriber(RabbitClient):

    def start_consuming(self, callback):
        if self.channel is None:
            raise Exception("Not connected to RabbitMQ. Call connect() first.")

        self.channel.basic_consume(queue=self.queue, on_message_callback=callback, auto_ack=True)
        self.channel.start_consuming()
