#include <cstdio>
#include <cstring>
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

        T result = main_.top();
        main_.pop();

        while (!aux_.empty()) {
            T& top = aux_.top();
            aux_.pop();
            main_.push(top);
        }
        return result;
    }
};

void testQueueFromTwoStacks() {
    printf("\n");
    printf("Test QueueFromTwoStacks:\n");
    printf("========================\n");

    QueueFromTwoStacks<char*> q;

    char a[] = "a";
    char b[] = "b";
    char c[] = "c";
    char d[] = "d";
    char e[] = "e";

    printf("Enqueue a\n");
    q.enqueue(a);
    printf("Enqueue b\n");
    q.enqueue(b);
    printf("Enqueue c\n");
    q.enqueue(c);
    printf("Enqueue d\n");
    q.enqueue(d);
    printf("Enqueue e\n");
    q.enqueue(e);

    printf("\n");

    char* d1 = q.dequeue();
    printf("Dequeue: %s\n", d1);
    char* d2 = q.dequeue();
    printf("Dequeue: %s\n", d2);
    char* d3 = q.dequeue();
    printf("Dequeue: %s\n", d3);
    char* d4 = q.dequeue();
    printf("Dequeue: %s\n", d4);
    char* d5 = q.dequeue();
    printf("Dequeue: %s\n", d5);

    char* d6 = q.dequeue();
    printf("Dequeue: %s\n", (d6 == nullptr) ? "<empty>" : d6);
}
