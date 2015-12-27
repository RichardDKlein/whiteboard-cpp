#include <cstdio>
#include <set>
#include <vector>

using namespace std;

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
    vector<Pair> result;
    set<int> seen;
    for (auto& v1: v) {
        int v2 = sum - v1;
        if (seen.count(v2) > 0) {
            Pair p(v1, v2);
            result.push_back(p);
        }
        seen.insert(v1);
    }
    return result;
}

void testSumPairsInUnsortedArray() {
    printf("\n");
    printf("Test sumPairsInUnsortedArray():\n");
    printf("===============================\n");
    int a[] = {-2, -1, 0, 3, 5, 6, 7, 9, 13, 14};
    vector<int> v;
    for (auto& elt : a) {
        v.push_back(elt);
        printf("%d ", elt);
    }
    printf("\n");
    int sum = 12;
    vector<Pair> pairs = sumPairsInUnsortedArray(v, sum);
    for (auto& thePair : pairs) {
        printf("%d + %d = %d\n", thePair.first, thePair.second,
            thePair.first + thePair.second);
    }
}
