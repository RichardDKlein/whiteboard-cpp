#pragma once
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
            T front = main_.front();
            main_.pop();
            aux_.push(front);
        }
        T result = main_.front();
        main_.pop();

        while (!aux_.empty()) {
            T front = aux_.front();
            aux_.pop();
            main_.push(front);
        }
        return result;
    }
};
