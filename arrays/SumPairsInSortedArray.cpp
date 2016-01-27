#include "Arrays.h"

using Pair = pair<int, int>;

/**
 * @brief In a sorted array, find pairs of array elements
 * that sum to a given value.
 *
 * @param v The sorted array to search for pairs.
 * @param sum The value to which each pair of elements should sum.
 * @return A vector of pairs that sum to the specified value.
 */
vector<Pair> sumPairsInSortedArray(vector<int> v, int sum) {
    vector<Pair> pairs;
    int left = 0;
    int right = v.size() - 1;
    while (left < right) {
        if (v[left] + v[right] < sum) {
            ++left;
        } else if (v[left] + v[right] > sum) {
            --right;
        } else {
            pairs.push_back(Pair(v[left++], v[right--]));
        }
    }
    return pairs;
}

void testSumPairsInSortedArray() {
    cout << endl;
    cout << "Test sumPairsInSortedArray():" << endl;
    cout << "=============================" << endl;

    int a[] = {-2, -1, 0, 3, 5, 6, 6, 7, 9, 13, 14};
    int count = sizeof(a) / sizeof(a[0]);

    vector<int> v = arrayToVector(count, a);
    cout << "sorted array = " << vectorToString(v) << endl;

    int sum = 12;
    vector<Pair> pairs = sumPairsInSortedArray(v, sum);

    for (auto& p : pairs) {
        int p1 = p.first;
        int p2 = p.second;
        int sum = p1 + p2;
        cout << p1 << " + " << p2 << " = " << sum << endl;
    }
}
