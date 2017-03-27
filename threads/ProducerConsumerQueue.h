#pragma once

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

using namespace std;

template <typename T>
class ProducerConsumerQueue {
private:
    queue<T> queue_;
    size_t capacity_;
    mutex mutex_;
    condition_variable notFull_;
    condition_variable notEmpty_;
public:
    ProducerConsumerQueue(int capacity) : capacity_(capacity) {}
    void push(const T& item) {
        unique_lock<mutex> lock(mutex_);
        notFull_.wait(lock, [this](){
            return queue_.size() < capacity_;
        });
        queue_.push(item);
        notEmpty_.notify_all();
    }
    T pop() {
        unique_lock<mutex> lock(mutex_);
        notEmpty_.wait(lock, [this](){
            return !queue_.empty();
        });
        T front = queue_.front();
        queue_.pop();
        notFull_.notify_all();
        return front;
    }
};
