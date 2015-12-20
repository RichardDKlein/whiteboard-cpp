#include <cstdio>
#include <set>
#include "TestUtils.h"

using namespace std;

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
    set<T> s1 = s;
    T first = *s1.begin();
    s1.erase(s1.begin());
    set<set<T>> remPowerSet = powerSetRecursive(s1);
    result = remPowerSet;
    for (auto subset : remPowerSet) {
        subset.insert(first);
        result.insert(subset);
    }
    return result;
}

void testPowerSetRecursive() {
    printf("\n");
    printf("Test powerSetRecursive():\n");
    printf("=========================\n");

    set<char> s;

    s.insert('a');
    s.insert('b');
    s.insert('c');
    s.insert('d');
    s.insert('e');

    printf("s = ");
    printSet(s);

    set<set<char>> p = powerSetRecursive(s);
    printf("powerSetRecursive(s) = %d subsets:\n", p.size());
    printPowerSet(p);
}
