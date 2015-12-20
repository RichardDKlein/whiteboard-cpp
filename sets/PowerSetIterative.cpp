#include <cmath>
#include <cstdio>
#include <iterator>
#include <set>
#include "TestUtils.h"

using namespace std;

int getBit(unsigned int n, int b);

/**
 * @brief Return the power set of a set, i.e. the set of all subsets
 * of that set, using iteration.
 *
 * @param s The set of interest.
 * @return The power set of |s|.
 */
template<typename T>
set<set<T>> powerSetIterative(const set<T>& s) {
    set<set<T>> result;
    unsigned int numSubsets = pow(2, s.size());
    for (unsigned int i = 0; i < numSubsets; ++i) {
        set<T> subset;
        typename set<T>::iterator iter = s.begin();
        for (int bit = 0; bit < s.size(); ++bit, ++iter) {
            if (getBit(i, bit) == 1) {
                subset.insert(*iter);
            }
        }
        result.insert(subset);
    }
    return result;
}

void testPowerSetIterative() {
    printf("\n");
    printf("Test powerSetIterative():\n");
    printf("=========================\n");

    set<char> s;

    s.insert('a');
    s.insert('b');
    s.insert('c');
    s.insert('d');
    s.insert('e');

    printf("s = ");
    printSet(s);

    set<set<char>> p = powerSetIterative(s);
    printf("powerSetIterative(s) = %d subsets:\n", p.size());
    printPowerSet(p);
}
