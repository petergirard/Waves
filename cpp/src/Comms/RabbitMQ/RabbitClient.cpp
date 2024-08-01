//
// Created by Peter on 6/24/2024.
//

#include "RabbitClient.h"

#include "RabbitClient.h"

#include <utility>

RabbitClient::RabbitClient(std::string queueName) : queue(std::move(queueName)){}


RabbitClient::~RabbitClient() {
    closeConnection();
}

void RabbitClient::connect() {
    AmqpClient::Channel::OpenOpts opts;
    opts.host = HOST;
    opts.vhost = "/";
    opts.port = 5672; // default RabbitMQ port
    AmqpClient::Channel::OpenOpts::BasicAuth auth(
            "guest", // default RabbitMQ username
            "guest"); // default RabbitMQ password
    opts.auth = auth;

    channel = AmqpClient::Channel::Open(opts);
    channel->DeclareExchange(EXCHANGE, EXCHANGE_TYPE);
    if (!queue.empty()) {
        channel->DeclareQueue(queue, false, true, false, false);
        channel->BindQueue(queue, EXCHANGE, ROUTING_KEY);
    }
}

void RabbitClient::closeConnection() {
    if (channel) {
        channel.reset();
    }
}