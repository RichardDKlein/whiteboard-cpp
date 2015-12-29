#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <sstream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
string vectorToString(const vector<T>& v) {
    ostringstream oss;
    oss << "[ ";
    for (auto& v1 : v) {
        oss << v1 << " ";
    }
    oss << "]";
    return oss.str();
}

#endif // #ifndef TEST_UTILS_H
