#include <cstdio>
#include <vector>

using namespace std;

/**
 * @brief In a sorted array, find pairs of array elements
 * that sum to a given value.
 *
 * @param v The sorted array to search for pairs.
 * @param sum The value to which each pair of elements should sum.
 * @return A vector of pairs that sum to the specified value.
 */
vector<pair<int, int>>
sumPairsInSortedArray(vector<int> v, int sum) {
    vector<pair<int, int>> pairs;
    int first = 0;
    int last = v.size() - 1;
    while (first < last) {
        if (v[first] + v[last] > sum) {
            last--;
        } else if (v[first] + v[last] < sum) {
            first++;
        } else {
            pair<int, int> thePair(v[first], v[last]);
            pairs.push_back(thePair);
            first++;
            last--;
        }
    }
    return pairs;
}

void testSumPairsInSortedArray() {
    printf("\n");
    printf("Test sumPairsInSortedArray():\n");
    printf("=============================\n");

    int a[] = {-2, -1, 0, 3, 5, 6, 7, 9, 13, 14};

    vector<int> v;
    for (auto& elt : a) {
        v.push_back(elt);
        printf("%d ", elt);
    }
    printf("\n");

    int sum = 12;
    vector<pair<int, int>> pairs = sumPairsInSortedArray(v, sum);

    for (auto& thePair : pairs) {
        printf("%d + %d = %d\n", thePair.first, thePair.second,
            thePair.first + thePair.second);
    }
}
