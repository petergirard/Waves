//
// Created by Peter on 7/12/2024.
//

#ifndef WAVES_CONCURRENTQUEUE_H
#define WAVES_CONCURRENTQUEUE_H


#include <queue>
#include <mutex>
#include <condition_variable>
#include <stdexcept>

template<typename T>
class ConcurrentQueue {
public:
    ConcurrentQueue() = default;
    ~ConcurrentQueue() = default;

    // Add an item to the queue
    void enqueue(T item) {
        std::lock_guard<std::mutex> lock(mtx);
        queue.push(std::move(item));
        cv.notify_one();
    }

    // Remove and return an item from the queue
    T dequeue() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return !queue.empty(); });
        T item = std::move(queue.front());
        queue.pop();
        return item;
    }

    // Check if the queue is empty
    bool empty() const {
        std::lock_guard<std::mutex> lock(mtx);
        return queue.empty();
    }

private:
    mutable std::mutex mtx;
    std::condition_variable cv;
    std::queue<T> queue;
};


#endif //WAVES_CONCURRENTQUEUE_H
