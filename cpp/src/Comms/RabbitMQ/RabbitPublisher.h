//
// Created by Peter on 6/24/2024.
//

#ifndef WAVES_RABBITPUBLISHER_H
#define WAVES_RABBITPUBLISHER_H

#include "RabbitClient.h"

class RabbitPublisher : public RabbitClient {
public:
    using RabbitClient::RabbitClient;
    void publishMessage(const std::string &message, bool persistent = false);
};


#endif //WAVES_RABBITPUBLISHER_H
