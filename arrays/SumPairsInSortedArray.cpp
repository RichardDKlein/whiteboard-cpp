#include "Arrays.h"

typedef pair<int, int> Pair;

/**
 * @brief In a sorted array, find pairs of array elements
 * that sum to a given value.
 *
 * @param v The sorted array to search for pairs.
 * @param sum The value to which each pair of elements should sum.
 * @return A vector of pairs that sum to the specified value.
 */
vector<Pair> sumPairsInSortedArray(vector<int> v, int sum) {
    vector<Pair> result;
    int left = 0;
    int right = v.size() - 1;
    while (left < right) {
        int v1 = v[left];
        int v2 = v[right];
        int s = v1 + v2;
        if (s > sum) {
            --right;
        } else if (s < sum) {
            ++left;
        } else {
            Pair p(v1, v2);
            result.push_back(p);
            ++left;
            --right;
        }
    }
    return result;
}

void testSumPairsInSortedArray() {
    cout << endl;
    cout << "Test sumPairsInSortedArray():" << endl;
    cout << "=============================" << endl;

    int a[] = {-2, -1, 0, 3, 5, 6, 7, 9, 13, 14};

    vector<int> v;
    for (auto n : a) {
        v.push_back(n);
        cout << n << " ";
    }
    cout << endl;

    int sum = 12;
    vector<Pair> pairs = sumPairsInSortedArray(v, sum);

    for (auto& p : pairs) {
        int p1 = p.first;
        int p2 = p.second;
        int sum = p1 + p2;
        cout << p1 << " + " << p2 << " = " << sum << endl;
    }
}
