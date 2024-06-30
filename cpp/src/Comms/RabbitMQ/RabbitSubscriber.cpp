//
// Created by Peter on 6/24/2024.
//

#include "RabbitSubscriber.h"
#include <stdexcept>

RabbitSubscriber::~RabbitSubscriber() {
    stopConsuming();
}

void RabbitSubscriber::startConsuming(const std::function<void(const std::string &)> &callback) {
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
                callback(envelope->Message()->Body());
            }
        }
    });
}

void RabbitSubscriber::stopConsuming() {
    if (is_consuming) {
        is_consuming = false;
        if (consuming_thread.joinable()) {
            consuming_thread.join();
        }
    }
}
