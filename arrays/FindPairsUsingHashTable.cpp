#include <cstdio>
#include <set>
#include <vector>

using namespace std;

/**
 * @brief Find pairs of array elements that sum to a given value,
 * using a hash table.
 *
 * @param v The array to search for pairs.
 * @param sum The value to which each pair of elements should sum.
 * @return A vector of pairs that sum to the specified value.
 */
vector<pair<int, int>> findPairsUsingHashTable(vector<int> v, int sum) {
    vector<pair<int, int>> pairs;
    set<int> seen;
    for (auto& val: v) {
        if (seen.count(sum - val) > 0) {
            pair<int, int> thePair(val, sum - val);
            pairs.push_back(thePair);
        }
        seen.insert(val);
    }
    return pairs;
}

void testFindPairsUsingHashTable() {
	printf("\n");
	printf("Test findPairsUsingHashTable():\n");
	printf("===============================\n");
	int a[] = {-2, -1, 0, 3, 5, 6, 7, 9, 13, 14};
	vector<int> v;
	for (auto& elt : a) {
		v.push_back(elt);
		printf("%d ", elt);
	}
	printf("\n");
	int sum = 12;
	vector<pair<int, int>> pairs = findPairsUsingHashTable(v, sum);
	for (auto& thePair : pairs) {
		printf("%d + %d = %d\n", thePair.first, thePair.second,
			thePair.first + thePair.second);
	}
}
