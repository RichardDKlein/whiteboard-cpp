#include <iostream>
#include <stack>

using namespace std;

template<typename T>
class QueueFromTwoStacks {
private:
    stack<T> main_;
    stack<T> aux_;
public:
    void enqueue(const T& item) {
        main_.push(item);
    }
    T dequeue() {
        if (main_.empty()) {
            return T();
        }
        while (main_.size() > 1) {
            T& top = main_.top();
            main_.pop();
            aux_.push(top);
        }

        T front = main_.top();
        main_.pop();

        while (!aux_.empty()) {
            T& top = aux_.top();
            aux_.pop();
            main_.push(top);
        }
        return front;
    }
};

void testQueueFromTwoStacks() {
    cout << endl;
    cout << "Test QueueFromTwoStacks:" << endl;
    cout << "========================" << endl;

    QueueFromTwoStacks<char*> q;

    char a[] = "a";
    char b[] = "b";
    char c[] = "c";
    char d[] = "d";
    char e[] = "e";

    cout << "Enqueue a" << endl;
    q.enqueue(a);
    cout << "Enqueue b" << endl;
    q.enqueue(b);
    cout << "Enqueue c" << endl;
    q.enqueue(c);
    cout << "Enqueue d" << endl;
    q.enqueue(d);
    cout << "Enqueue e" << endl;
    q.enqueue(e);

    cout << endl;

    char* d1 = q.dequeue();
    cout << "Dequeue: " << d1 << endl;
    char* d2 = q.dequeue();
    cout << "Dequeue: " << d2 << endl;
    char* d3 = q.dequeue();
    cout << "Dequeue: " << d3 << endl;
    char* d4 = q.dequeue();
    cout << "Dequeue: " << d4 << endl;
    char* d5 = q.dequeue();
    cout << "Dequeue: " << d5 << endl;

    char* d6 = q.dequeue();
    cout << "Dequeue: " << ((d6 == nullptr) ? "<empty>" : d6) << endl;
}
