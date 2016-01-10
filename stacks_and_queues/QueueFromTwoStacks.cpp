#include <iostream>
#include <stack>

using namespace std;

template<typename T>
class QueueFromTwoStacks {
private:
    stack<T> main_;
    stack<T> aux_;
public:
    void push(const T& item) {
        main_.push(item);
    }
    T pop() {
        if (main_.empty()) {
            return T();
        }
        while (main_.size() > 1) {
            T top = main_.top();
            main_.pop();
            aux_.push(top);
        }
        T result = main_.top();
        main_.pop();

        while (!aux_.empty()) {
            T top = aux_.top();
            aux_.pop();
            main_.push(top);
        }
        return result;
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

    cout << "Push a" << endl;
    q.push(a);
    cout << "Push b" << endl;
    q.push(b);
    cout << "Push c" << endl;
    q.push(c);
    cout << "Push d" << endl;
    q.push(d);
    cout << "Push e" << endl;
    q.push(e);

    cout << endl;

    char* d1 = q.pop();
    cout << "Pop: " << d1 << endl;
    char* d2 = q.pop();
    cout << "Pop: " << d2 << endl;
    char* d3 = q.pop();
    cout << "Pop: " << d3 << endl;
    char* d4 = q.pop();
    cout << "Pop: " << d4 << endl;
    char* d5 = q.pop();
    cout << "Pop: " << d5 << endl;

    char* d6 = q.pop();
    cout << "Pop: " << ((d6 == nullptr) ? "<empty>" : d6) << endl;
}
