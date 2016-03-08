#include <iostream>
#include <set>

using namespace std;

template<typename T>
void printSet(set<T> s) {
    cout << "{ ";
    for (const auto& elt : s) {
        cout << elt << " ";
    }
    cout << "}" << endl;
}

template<typename T>
void printPowerSet(set<set<T>> p) {
    cout << "{" << endl;
    for (const auto& s : p) {
        cout << "\t";
        printSet(s);
    }
    cout << "}" << endl;
}
