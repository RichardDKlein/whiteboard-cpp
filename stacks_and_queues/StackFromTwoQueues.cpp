#include <iostream>
#include <queue>

using namespace std;

template<typename T>
class StackFromTwoQueues {
private:
    queue<T> main_;
    queue<T> aux_;
public:
    void push(const T& item) {
        main_.push(item);
    }
    T pop() {
        if (main_.empty()) {
            return T();
        }
        while (main_.size() > 1) {
            T& front = main_.front();
            main_.pop();
            aux_.push(front);
        }

        T top = main_.front();
        main_.pop();

        while (!aux_.empty()) {
            T& front = aux_.front();
            aux_.pop();
            main_.push(front);
        }
        return top;
    }
};

void testStackFromTwoQueues() {
    cout << endl;
    cout << "Test StackFromTwoQueues:" << endl;
    cout << "========================" << endl;

    StackFromTwoQueues<char*> s;

    char a[] = "a";
    char b[] = "b";
    char c[] = "c";
    char d[] = "d";
    char e[] = "e";

    cout << "Push a" << endl;
    s.push(a);
    cout << "Push b" << endl;
    s.push(b);
    cout << "Push c" << endl;
    s.push(c);
    cout << "Push d" << endl;
    s.push(d);
    cout << "Push e" << endl;
    s.push(e);

    cout << endl;

    char* p1 = s.pop();
    cout << "Pop: " << p1 << endl;
    char* p2 = s.pop();
    cout << "Pop: " << p2 << endl;
    char* p3 = s.pop();
    cout << "Pop: " << p3 << endl;
    char* p4 = s.pop();
    cout << "Pop: " << p4 << endl;
    char* p5 = s.pop();
    cout << "Pop: " << p5 << endl;

    char* p6 = s.pop();
    cout << "Pop: " << ((p6 == nullptr) ? "<empty>" : p6) << endl;
}
