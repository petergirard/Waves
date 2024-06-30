//
// Created by Peter on 6/24/2024.
//

#ifndef WAVES_RABBITCLIENT_H
#define WAVES_RABBITCLIENT_H

#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <string>

class RabbitClient {
public:
    explicit RabbitClient(std::string host = "localhost",
                          std::string exchange = "default_exchange",
                          std::string exchange_type = "direct",
                          std::string queue = "",
                          std::string routing_key = "");
    virtual ~RabbitClient();

    void connect();
    void closeConnection();

protected:
    std::string host;
    std::string exchange;
    std::string exchange_type;
    std::string queue;
    std::string routing_key;

    AmqpClient::Channel::ptr_t channel;
};

#endif //WAVES_RABBITCLIENT_H
