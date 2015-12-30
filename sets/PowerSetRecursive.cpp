#include "Sets.h"

/**
 * @brief Return the power set of a set, i.e. the set of all subsets
 * of that set, using recursion.
 *
 * @param s The set of interest.
 * @return The power set of |s|.
 */
template<typename T>
set<set<T>> powerSetRecursive(const set<T>& s) {
    set<set<T>> result;
    if (s.empty()) {
        set<T> emptySet;
        result.insert(emptySet);
        return result;
    }
    set<T> rem = s;
    T first = *rem.begin();
    rem.erase(rem.begin());
    set<set<T>> remPowerSet = powerSetRecursive(rem);
    result = remPowerSet;
    for (auto subset : remPowerSet) {
        subset.insert(first);
        result.insert(subset);
    }
    return result;
}

void testPowerSetRecursive() {
    cout << endl;
    cout << "Test powerSetRecursive():" << endl;
    cout << "=========================" << endl;

    set<char> s;

    s.insert('a');
    s.insert('b');
    s.insert('c');
    s.insert('d');
    s.insert('e');

    cout << "s = ";
    printSet(s);

    set<set<char>> p = powerSetRecursive(s);
    cout << "powerSetRecursive(s) = " << p.size()
         << " subsets:" << endl;
    printPowerSet(p);
}
