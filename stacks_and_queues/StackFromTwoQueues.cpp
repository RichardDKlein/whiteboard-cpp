#include <cstdio>
#include <cstring>
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

        T result = main_.front();
        main_.pop();

        while (!aux_.empty()) {
            T& front = aux_.front();
            aux_.pop();
            main_.push(front);
        }
        return result;
    }
};

void testStackFromTwoQueues() {
    printf("\n");
    printf("Test StackFromTwoQueues:\n");
    printf("========================\n");

    StackFromTwoQueues<char*> s;

    char a[] = "a";
    char b[] = "b";
    char c[] = "c";
    char d[] = "d";
    char e[] = "e";

    printf("Push a\n");
    s.push(a);
    printf("Push b\n");
    s.push(b);
    printf("Push c\n");
    s.push(c);
    printf("Push d\n");
    s.push(d);
    printf("Push e\n");
    s.push(e);

    printf("\n");

    char* p1 = s.pop();
    printf("Pop: %s\n", p1);
    char* p2 = s.pop();
    printf("Pop: %s\n", p2);
    char* p3 = s.pop();
    printf("Pop: %s\n", p3);
    char* p4 = s.pop();
    printf("Pop: %s\n", p4);
    char* p5 = s.pop();
    printf("Pop: %s\n", p5);

    char* p6 = s.pop();
    printf("Pop: %s\n", (p6 == nullptr) ? "<empty>" : p6);
}
