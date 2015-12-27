#include <cstdio>
#include <vector>

using namespace std;

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
    vector<Pair> pairs = sumPairsInSortedArray(v, sum);

    for (auto& thePair : pairs) {
        printf("%d + %d = %d\n", thePair.first, thePair.second,
            thePair.first + thePair.second);
    }
}
