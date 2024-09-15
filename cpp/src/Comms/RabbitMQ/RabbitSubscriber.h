//
// Created by Peter on 6/24/2024.
//

#ifndef WAVES_RABBITSUBSCRIBER_H
#define WAVES_RABBITSUBSCRIBER_H

#include "RabbitClient.h"
#include <functional>
#include <thread>
#include <atomic>
#include "../Json/JsonSerialization.h"

template <typename T>
class RabbitSubscriber : public RabbitClient {
public:
    using RabbitClient::RabbitClient;
    ~RabbitSubscriber() override;

    void startConsuming(const std::function<void(const T&)>& callback);
    void stopConsuming();

private:
    std::thread consumingThread;
    std::atomic<bool> isConsuming{false};
};

template<typename T>
RabbitSubscriber<T>::~RabbitSubscriber() {
    stopConsuming();
}

template<typename T>
void RabbitSubscriber<T>::startConsuming(const std::function<void(const T&)>& callback) {
    if (!channel) {
        throw std::runtime_error("Not connected to RabbitMQ. Call connect() first.");
    }
    isConsuming = true;
    consumingThread = std::thread([this, callback]() {
        channel->BasicConsume(queue, "", true, false, false, 1);
        while (isConsuming) {
            AmqpClient::Envelope::ptr_t envelope;
            bool success = channel->BasicConsumeMessage(envelope);
            if (success) {
                // Convert message body from JSON to T
                auto body = envelope->Message()->Body();
                T message = nlohmann::json::parse(body).get<T>();
                callback(message);
            }
        }
    });
}

template<typename T>
void RabbitSubscriber<T>::stopConsuming() {
    if (isConsuming) {
        isConsuming = false;
        if (consumingThread.joinable()) {
            consumingThread.join();
        }
    }
}

#endif //WAVES_RABBITSUBSCRIBER_H
