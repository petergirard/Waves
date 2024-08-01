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
    std::thread consuming_thread;
    std::atomic<bool> is_consuming{false};
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
    is_consuming = true;
    consuming_thread = std::thread([this, callback]() {
        channel->BasicConsume(queue, "", true, false, false, 1);
        while (is_consuming) {
            AmqpClient::Envelope::ptr_t envelope;
            bool success = channel->BasicConsumeMessage(envelope);
            if (success) {
                // Convert message body from JSON to T
                T message = nlohmann::json::parse(envelope->Message()->Body()).get<T>();
                callback(message);
            }
        }
    });
}

template<typename T>
void RabbitSubscriber<T>::stopConsuming() {
    if (is_consuming) {
        is_consuming = false;
        if (consuming_thread.joinable()) {
            consuming_thread.join();
        }
    }
}

#endif //WAVES_RABBITSUBSCRIBER_H
