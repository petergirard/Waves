//
// Created by Peter on 6/24/2024.
//

#ifndef WAVES_RABBITCLIENT_H
#define WAVES_RABBITCLIENT_H

#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <string>
#include "../IConnectable.h"

class RabbitClient : public IConnectable {
public:
    explicit RabbitClient(std::string queueName);
    ~RabbitClient() override;

    void connect() override;
    void closeConnection() override;

protected:
    const std::string HOST = "localhost";
    const std::string EXCHANGE = "Waves";
    const std::string EXCHANGE_TYPE = "fanout";
    const std::string ROUTING_KEY = "";

    std::string queue;
    AmqpClient::Channel::ptr_t channel;
};

#endif //WAVES_RABBITCLIENT_H
