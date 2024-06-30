//
// Created by Peter on 6/24/2024.
//

#ifndef WAVES_RABBITSUBSCRIBER_H
#define WAVES_RABBITSUBSCRIBER_H

#include "RabbitClient.h"
#include <functional>
#include <thread>
#include <atomic>

class RabbitSubscriber : public RabbitClient {
public:
    using RabbitClient::RabbitClient;
    ~RabbitSubscriber() override;

    void startConsuming(const std::function<void(const std::string &)> &callback);
    void stopConsuming();

private:
    std::thread consuming_thread;
    std::atomic<bool> is_consuming;
};

#endif //WAVES_RABBITSUBSCRIBER_H
