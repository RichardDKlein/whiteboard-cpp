#include <condition_variable>
#include <cstdio>
#include <mutex>
#include <queue>
#include <thread>

using namespace std;

template <class J>
class ProducerConsumerQueue {
private:
    queue<J> m_jobQueue;
    size_t m_maxJobs;
    mutex m_mutex;
    condition_variable m_notFull;
    condition_variable m_notEmpty;

public:
    ProducerConsumerQueue(int maxJobs) : m_maxJobs(maxJobs) {}

    void putJob(J job) {
        unique_lock<mutex> lock(m_mutex);
        m_notFull.wait(lock,
            [this](){return m_jobQueue.size() < m_maxJobs;});
        m_jobQueue.push(job);
        m_notEmpty.notify_all();
    }

    int getJob() {
        unique_lock<mutex> lock(m_mutex);
        m_notEmpty.wait(lock,
            [this](){return m_jobQueue.size() > 0;});
        J job = m_jobQueue.front();
        m_jobQueue.pop();
        m_notFull.notify_all();
        return job;
    }
};

static void consumer(int id, ProducerConsumerQueue<int>* jobQueue);
static void producer(int id, ProducerConsumerQueue<int>* jobQueue);

void testProducerConsumerQueue() {
    printf("\n");
    printf("Test ProducerConsumerQueue():\n");
    printf("=============================\n");

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

static void consumer(int id, ProducerConsumerQueue<int>* jobQueue) {
    for (int i = 0; i < 10; ++i) {
        int job = jobQueue->getJob();
        printf("Consumer %d consumed %d\n", id, job);
        this_thread::sleep_for(chrono::milliseconds(250));
    }
}

static void producer(int id, ProducerConsumerQueue<int>* jobQueue) {
    for (int i = 0; i < 10; ++i) {
        int job = (id * 100) + i;
        jobQueue->putJob(job);
        printf("Producer %d produced %d\n", id, job);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}
