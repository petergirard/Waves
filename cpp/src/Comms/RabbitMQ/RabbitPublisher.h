//
// Created by Peter on 6/24/2024.
//

#ifndef WAVES_RABBITPUBLISHER_H
#define WAVES_RABBITPUBLISHER_H

#include <nlohmann/json.hpp>
#include "RabbitClient.h"

template <typename T>
class RabbitPublisher : public RabbitClient {
public:
    using RabbitClient::RabbitClient;
    void publish(const T& report);
};

template<typename T>
void RabbitPublisher<T>::publish(const T &report) {
    if (!channel) {
        throw std::runtime_error("Not connected to RabbitMQ. Call connect() first.");
    }

    nlohmann::json json_message = report;
    std::string message = json_message.dump();

    AmqpClient::BasicMessage::ptr_t msg = AmqpClient::BasicMessage::Create(message);
    msg->DeliveryMode(AmqpClient::BasicMessage::dm_nonpersistent);

    channel->BasicPublish(EXCHANGE, ROUTING_KEY, msg);
}

#endif //WAVES_RABBITPUBLISHER_H
