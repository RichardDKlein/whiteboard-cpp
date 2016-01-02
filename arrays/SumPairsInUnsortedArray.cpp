#include "Arrays.h"

typedef pair<int, int> Pair;

/**
 * @brief In an unsorted array, find pairs of array elements
 * that sum to a given value.
 *
 * @param v The unsorted array to search for pairs.
 * @param sum The value to which each pair of elements should sum.
 * @return A vector of pairs that sum to the specified value.
 */
vector<Pair> sumPairsInUnsortedArray(vector<int> v, int sum) {
    vector<Pair> pairs;
    set<int> seen;
    for (auto& v1: v) {
        int v2 = sum - v1;
        if (seen.count(v2) > 0) {
            Pair p(v1, v2);
            pairs.push_back(p);
        }
        seen.insert(v1);
    }
    return pairs;
}

void testSumPairsInUnsortedArray() {
    cout << endl;
    cout << "Test sumPairsInUnsortedArray():" << endl;
    cout << "===============================" << endl;

    int a[] = {-2, -1, 0, 3, 5, 6, 7, 9, 13, 14};

    vector<int> v;
    for (auto n : a) {
        v.push_back(n);
        cout << n << " ";
    }
    cout << endl;

    int sum = 12;
    vector<Pair> pairs = sumPairsInUnsortedArray(v, sum);

    for (auto& p : pairs) {
        int p1 = p.first;
        int p2 = p.second;
        int sum = p1 + p2;
        cout << p1 << " + " << p2 << " = " << sum << endl;
    }
}
