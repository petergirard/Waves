import pika


class RabbitClient:
    def __init__(self, host='localhost', exchange='default_exchange', exchange_type='direct', queue='', routing_key=''):
        self.host = host
        self.exchange = exchange
        self.exchange_type = exchange_type
        self.queue = queue
        self.routing_key = routing_key
        self.connection = None
        self.channel = None

    def connect(self):
        """Establish connection to RabbitMQ server."""
        self.connection = pika.BlockingConnection(pika.ConnectionParameters(self.host))
        self.channel = self.connection.channel()
        self.channel.exchange_declare(exchange=self.exchange, exchange_type=self.exchange_type)
        if self.queue:
            self.channel.queue_declare(queue=self.queue, passive=False, durable=True, exclusive=False, auto_delete=False)
            self.channel.queue_bind(exchange=self.exchange, queue=self.queue, routing_key=self.routing_key)

    def close_connection(self):
        """Close the connection to RabbitMQ server."""
        if self.connection:
            self.connection.close()
            self.connection = None
            self.channel = None
