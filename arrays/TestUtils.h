#ifndef ARRAYS_TEST_UTILS_H
#define ARRAYS_TEST_UTILS_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
string arrayToString(int count, T a[]) {
    ostringstream oss;
    oss << "[ ";
    for (int i = 0; i < count; i++) {
        oss << a[i] << " ";
    }
    oss << "]";
    return oss.str();
}

template<typename T>
vector<T> arrayToVector(int count, T a[]) {
    vector<T> v;
    for (int i = 0; i < count; ++i) {
        v.push_back(a[i]);
    }
    return v;
}

template<typename T>
string vectorToString(vector<T> v) {
    ostringstream oss;
    oss << "[ ";
    for (auto& t : v) {
        oss << t << " ";
    }
    oss << "]";
    return oss.str();
}

#endif // #ifndef ARRAYS_TEST_UTILS_H