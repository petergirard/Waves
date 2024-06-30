//
// Created by Peter on 6/24/2024.
//

#include "RabbitPublisher.h"

#include <stdexcept>

void RabbitPublisher::publishMessage(const std::string &message, bool persistent) {
    if (!channel) {
        throw std::runtime_error("Not connected to RabbitMQ. Call connect() first.");
    }

    AmqpClient::BasicMessage::ptr_t msg = AmqpClient::BasicMessage::Create(message);
    if (!persistent) {
        msg->DeliveryMode(AmqpClient::BasicMessage::dm_nonpersistent);
    }

    channel->BasicPublish(exchange, routing_key, msg);
}