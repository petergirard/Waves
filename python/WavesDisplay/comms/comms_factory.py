from comms.rabbit_publisher import RabbitPublisher
from comms.rabbit_subscriber import RabbitSubscriber


class CommsFactory:

    def get_subscriber(self, queue: str) -> RabbitSubscriber:
        return RabbitSubscriber(queue = queue)

    def get_publisher(self, queue: str) -> RabbitPublisher:
        return RabbitPublisher(queue = queue)