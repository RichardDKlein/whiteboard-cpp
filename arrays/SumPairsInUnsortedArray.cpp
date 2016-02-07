#include "Arrays.h"

using Pair = pair<int, int>;

/**
 * @brief In an unsorted array, find pairs of array elements
 * that sum to a given value.
 *
 * @param v The unsorted array to search for pairs.
 * @param sum The value to which each pair of elements should sum.
 * @return A vector of pairs that sum to the specified value.
 */
vector<Pair> sumPairsInUnsortedArray(const vector<int>& v, int sum) {
    vector<Pair> pairs;
    unordered_set<int> seen;
    for (auto& n : v) {
        if (seen.count(sum - n) > 0) {
            pairs.push_back(Pair(n, sum - n));
        }
        seen.insert(n);
    }
    return pairs;
}

void testSumPairsInUnsortedArray() {
    cout << endl;
    cout << "Test sumPairsInUnsortedArray():" << endl;
    cout << "===============================" << endl;

    int a[] = {-2, -1, 0, 3, 5, 6, 6, 7, 9, 13, 14};
    int count = sizeof(a) / sizeof(a[0]);

    vector<int> v = arrayToVector(count, a);
    shuffleArray(v);
    cout << "unsorted array = " << vectorToString(v) << endl;

    int sum = 12;
    vector<Pair> pairs = sumPairsInUnsortedArray(v, sum);

    for (auto& p : pairs) {
        int p1 = p.first;
        int p2 = p.second;
        int sum = p1 + p2;
        cout << p1 << " + " << p2 << " = " << sum << endl;
    }
}
