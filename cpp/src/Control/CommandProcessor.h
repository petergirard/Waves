//
// Created by Peter on 7/12/2024.
//

#ifndef WAVES_COMMANDPROCESSOR_H
#define WAVES_COMMANDPROCESSOR_H

#include <vector>
#include <functional>
#include "../Comms/IConnectable.h"
#include "../Comms/RabbitMQ/RabbitSubscriber.h"
#include "../Vehicle/Pilot.h"
#include "../Util/Thread/ConcurrentQueue.h"
#include "CommandProcessorBase.h"

template <typename T>
class CommandProcessor : public CommandProcessorBase {
public:
    explicit CommandProcessor(const std::string& queueName, std::function<void(Pilot&, const T&)> processCommandFunc)
            : subscriber(queueName), processCommandFunc(std::move(processCommandFunc)) {}

    void connect() override;
    void closeConnection() override;
    void executeCommands(Pilot& vehicle) override;

private:
    ConcurrentQueue<T> buffer{};
    RabbitSubscriber<T> subscriber;
    std::function<void(Pilot&, const T&)> processCommandFunc;
};

template<typename T>
void CommandProcessor<T>::executeCommands(Pilot& vehicle) {
    while (!buffer.empty()) {
        processCommandFunc(vehicle, buffer.dequeue());
    }
}

template<typename T>
void CommandProcessor<T>::connect() {
    subscriber.connect();
    subscriber.startConsuming([this](const T& command) {
        buffer.enqueue(command);
    });
}

template<typename T>
void CommandProcessor<T>::closeConnection() {
    subscriber.closeConnection();
}

#endif // WAVES_COMMANDPROCESSOR_H
