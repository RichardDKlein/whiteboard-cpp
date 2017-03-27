#pragma once
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
