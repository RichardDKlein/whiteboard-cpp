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

static void consumer(int id, ProducerConsumerQueue<int>* jobQueue);
static void producer(int id, ProducerConsumerQueue<int>* jobQueue);

void testProducerConsumerQueue() {
    cout << endl;
    cout << "Test ProducerConsumerQueue():" << endl;
    cout << "=============================" << endl;

    ProducerConsumerQueue<int> jobQueue(5);

    thread c1(consumer, 1, &jobQueue);
    thread c2(consumer, 2, &jobQueue);
    thread c3(consumer, 3, &jobQueue);
    thread p1(producer, 1, &jobQueue);
    thread p2(producer, 2, &jobQueue);
    thread p3(producer, 3, &jobQueue);

    c1.join();
    c2.join();
    c3.join();
    p1.join();
    p2.join();
    p3.join();
}

static mutex mutex_;

static void consumer(int id, ProducerConsumerQueue<int>* jobQueue) {
    unique_lock<mutex> lock(mutex_);
    lock.unlock();
    for (int i = 0; i < 10; ++i) {
        int job = jobQueue->pop();
        lock.lock(); // prevent interleaving of output
        cout << "Consumer " << id << " consumed " << job << endl;
        lock.unlock();
        this_thread::sleep_for(chrono::milliseconds(250));
    }
}

static void producer(int id, ProducerConsumerQueue<int>* jobQueue) {
    unique_lock<mutex> lock(mutex_);
    lock.unlock();
    for (int i = 0; i < 10; ++i) {
        int job = (id * 100) + i;
        jobQueue->push(job);
        lock.lock(); // prevent interleaving of output
        cout << "Producer " << id << " produced " << job << endl;
        lock.unlock();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}
