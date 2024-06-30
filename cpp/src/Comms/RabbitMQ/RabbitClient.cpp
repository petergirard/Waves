//
// Created by Peter on 6/24/2024.
//

#include "RabbitClient.h"

#include "RabbitClient.h"

#include <utility>

RabbitClient::RabbitClient(std::string host,
                           std::string exchange,
                           std::string exchange_type,
                           std::string queue,
                           std::string routing_key)
        : host(std::move(host)),
        exchange(std::move(exchange)),
        exchange_type(std::move(exchange_type)),
        queue(std::move(queue)),
        routing_key(std::move(routing_key)),
        channel(nullptr) {}

RabbitClient::~RabbitClient() {
    closeConnection();
}

void RabbitClient::connect() {
    AmqpClient::Channel::OpenOpts opts;
    opts.host = host;
    opts.vhost = "/";
    opts.port = 5672; // default RabbitMQ port
    AmqpClient::Channel::OpenOpts::BasicAuth auth(
            "guest", // default RabbitMQ username
            "guest"); // default RabbitMQ password
    opts.auth = auth;

    channel = AmqpClient::Channel::Open(opts);
    channel->DeclareExchange(exchange, exchange_type);
    if (!queue.empty()) {
        channel->DeclareQueue(queue);
        channel->BindQueue(queue, exchange, routing_key);
    }
}

void RabbitClient::closeConnection() {
    if (channel) {
        channel.reset();
    }
}
