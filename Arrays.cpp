#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <string>
#include <time.h>
#include <set>
#include <vector>

using namespace std;

// Search a sorted and rotated array
int search(vector<int> v, int target) {
    int left = 0;
    int right = v.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (v[mid] == target) {
            return mid;
        } else if (v[left] < v[mid]) { 
            // left half is normally ordered
            if (v[left] <= target && target <= v[mid]) {
                // search left
                right = mid - 1;
            } else {
                // search right
                left = mid + 1;
            }
        } else {
            // right half is normally ordered
            if (v[mid] <= target && target <= v[right]) {
                // search right
                left = mid + 1;
            } else {
                // search left
                right = mid - 1;
            }
        }
    }
    return -1;
}

// Find pairs of array elements that sum to a given value.
// (Version 1: Uses extra memory)
vector<pair<int, int>> findPairs1(vector<int> v, int sum) {
    vector<pair<int, int>> pairs;
    set<int> seen;
    for (auto val: v) {
        if (seen.count(sum - val) > 0) {
            pair<int, int> thePair(val, sum - val);
            pairs.push_back(thePair);
        }
        seen.insert(val);
    }
    return pairs;
}

// Find pairs of array elements that sum to a given value.
// (Version 2: Uses no extra memory)
vector<pair<int, int>> findPairs2(vector<int> v, int sum) {
    vector<pair<int, int>> pairs;
    sort(v.begin(), v.end());
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

// Returns the (begin, end) indices of all intervals of two or
// more consecutive integers occurring in an array of positive
// integers sorted in ascending order.
//
// For example, given the array {1, 2, 3, 5, 6, 10, 12, 14, 15},
// returns the pairs (0, 2), (3, 4), and (7, 8).

vector<pair<size_t,size_t>>
findIntervals(size_t count, int values[]) {
    vector<pair<size_t,size_t>> intervals;
    bool inInterval = false;
    size_t beginInterval = 0;
    size_t i;
    for (i = 1; i < count; i++) {
        if (!inInterval) {
            if (values[i] == values[i - 1] + 1) {
                inInterval = true;
                beginInterval = i - 1;
            }
        } else {
            if (values[i] != values[i - 1] + 1) {
                inInterval = false;
                pair<size_t,size_t>
                    interval(beginInterval, i - 1);
                intervals.push_back(interval);
            }
        }
    }
    if (inInterval) {
        pair<size_t,size_t> interval(beginInterval, i - 1);
        intervals.push_back(interval);
    }
    return intervals;
}

// Shuffle an array, as if it represented a deck of cards

int random(int min, int max) {
    static bool firstTime = true;
    if (firstTime) {
        srand((time(NULL)));
        firstTime = false;
    }
    return rand() % (max - min + 1) + min;
}

void shuffle(int count, int deck[]) {
    for (int i = 0; i < count - 1; i++) {
        // pick a random number j in the
        // interval [i + 1, count - 1]
        int min = i + 1;
        int max = count - 1;
        int j = random(min, max);
        // swap cards i and j
        int tmp = deck[i];
        deck[i] = deck[j];
        deck[j] = tmp;
    }
}

// Merge two sorted arrays into a single sorted array

int* merge(int count1, int a1[], int count2, int a2[]) {
    int* result = new int[count1 + count2];
    int i1 = 0;
    int i2 = 0;
    int iResult = 0;
    while ((i1 < count1) || (i2 < count2)) {
        if (i1 < count1) {
            if (i2 < count2) {
                if (a1[i1] < a2[i2]) {
                    result[iResult++] = a1[i1++];
                } else {
                    result[iResult++] = a2[i2++];
                }
            } else {
                // a1 non-empty, a2 empty
                result[iResult++] = a1[i1++];
            }
        } else {
            // a1 empty, a2 non-empty
            result[iResult++] = a2[i2++];
        }
    }
    return result;
}

// Calculate the amount of rain water (in feet, say)
// collected in the valleys between hills having
// given heights (also in feet) after a torrential
// downpour.
//
// The algorithm determines the waterline by extending
// the top of each hill horizontally until it touches
// the closest hills on the left and right. The time and
// space complexities are O(n*n) and O(n) respectively.

int calcWaterCollected(int count, int heights[]) {
    int* waterLine = new int[count];
    memcpy(waterLine, heights, count * sizeof(int));
    int left = 0;
    int right = count - 1;
    for (int i = left; i <= right; i++) {
        if (heights[i] < waterLine[i]) {
            continue; // hill is already underwater
        }
        if (i != left) {
            // find closest taller hill on left
            for (int j = i - 1; j >= left; j--) {
                if (heights[j] > heights[i]) {
                    // found taller hill
                    for (int k = i - 1; k > j; k--) {
                        waterLine[k] = heights[i];
                    }
                    break;
                }
            }
        }
        if (i != right) {
            // find closest taller hill on right
            for (int j = i + 1; j <= right; j++) {
                if (heights[j] > heights[i]) {
                    // found taller hill
                    for (int k = i + 1; k < j; k++) {
                        waterLine[k] = heights[i];
                    }
                    break;
                }
            }
        }
    }
    int waterCollected = 0;
    for (int i = left; i <= right; i++) {
        waterCollected += (waterLine[i] - heights[i]);
    }
    delete[] waterLine;
    return waterCollected;
}

// ==========================================================
//                          TESTING
// ==========================================================

// Helper functions for testing

string arrayToString(size_t count, int values[]) {
    string result = "[ ";
    for (size_t i = 0; i < count; i++) {
        char buf[32];
        sprintf(buf, "%d ", values[i]);
        result += buf;
    }
    result += "]";
    return result;
}

void printIntervals(const vector<pair<size_t,size_t>>& intervals) {
    printf("intervals = ");
    for (auto& interval : intervals) {
        printf("[%ld, %ld] ", interval.first, interval.second);
    }
    printf("\n");
}

void testArrays() {
    // Test search()
    {
        cout << endl << "Test search():" << endl;
        int a[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
        size_t len = sizeof(a) / sizeof(int);
        vector<int> v;
        for (size_t i = 0; i < len; ++i) {
            v.push_back(a[i]);
            cout << a[i] << " ";
        }
        cout << endl;
        for (size_t i = 0; i < v.size(); ++i) {
            int target = v[i];
            cout << "target = " << target << ", index = " <<
                search(v, target) << endl;
        }
        int target = 999;
        cout << "target = " << target << ", index = " <<
            search(v, target) << endl;
    }

    // Test findPairs1()
    {
        cout << endl << "Test findPairs1():" << endl;
        int a[] = {-2, -1, 0, 3, 5, 6, 7, 9, 13, 14};
        vector<int> v;
        for (auto elt : a) {
            v.push_back(elt);
            cout << elt << " ";
        }
        cout << endl;
        int sum = 12;
        vector<pair<int, int>> pairs = findPairs1(v, sum);
        for (auto thePair : pairs) {
            cout << thePair.first << " + " <<
                thePair.second << " = " <<
                thePair.first + thePair.second << endl;
        }
    }

    // Test findPairs2()
    {
        cout << endl << "Test findPairs2():" << endl;
        int a[] = {-2, -1, 0, 3, 5, 6, 7, 9, 13, 14};
        vector<int> v;
        for (auto elt : a) {
            v.push_back(elt);
            cout << elt << " ";
        }
        cout << endl;
        int sum = 12;
        vector<pair<int, int>> pairs = findPairs2(v, sum);
        for (auto thePair : pairs) {
            cout << thePair.first << " + " <<
                thePair.second << " = " <<
                thePair.first + thePair.second << endl;
        }
    }

    // Test findIntervals()
    printf("\nTest findIntervals():\n");
    {
        int values[] = {1, 3, 5, 6, 8, 9, 10, 14, 17};
        int count = sizeof(values) / sizeof(int);
        cout << arrayToString(count, values) << endl;
        printIntervals(findIntervals(count, values));
    }
    {
        int values[] = {1, 2, 3, 5, 6, 10, 12, 14, 15};
        int count = sizeof(values) / sizeof(int);
        cout << arrayToString(count, values) << endl;
        printIntervals(findIntervals(count, values));
    }
    {
        int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int count = sizeof(values) / sizeof(int);
        cout << arrayToString(count, values) << endl;
        printIntervals(findIntervals(count, values));
    }
    {
        int values[] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
        int count = sizeof(values) / sizeof(int);
        cout << arrayToString(count, values) << endl;
        printIntervals(findIntervals(count, values));
    }

    // Test shuffle()
    {
        printf("\nTest shuffle():\n");
        #define NUM_CARDS 52
        int deck[NUM_CARDS];
        for (int i = 0; i < NUM_CARDS; i++) {
            deck[i] = i;
        }
        cout << "Unshuffled deck = " <<
            arrayToString(NUM_CARDS, deck) << endl;
        for (int i = 0; i < 10; i++) {
            shuffle(NUM_CARDS, deck);
            cout << "Shuffled   deck = " <<
                arrayToString(NUM_CARDS, deck) << endl;
        }
    }

    // Test merge()
    {
        printf("\nTest merge():\n");
        #define COUNT1 sizeof(a1)/sizeof(int)
        #define COUNT2 sizeof(a2)/sizeof(int)
        {
            int a1[] = {1, 3, 5, 7, 9};
            int a2[] = {2, 4, 6, 8, 10};
            cout << "a1 = " <<
                arrayToString(COUNT1, a1) << endl;
            cout << "a2 = " <<
                arrayToString(COUNT2, a2) << endl;
            cout << "merged = " <<
                arrayToString(COUNT1 + COUNT2,
                merge(COUNT1, a1, COUNT2, a2)) << endl;
        }
        {
            int a1[] = {1, 3, 5, 7, 9};
            int a2[] = {2, 4, 6, 8, 10, 12, 14, 16};
            cout << "a1 = " <<
                arrayToString(COUNT1, a1) << endl;
            cout << "a2 = " <<
                arrayToString(COUNT2, a2) << endl;
            cout << "merged = " <<
                arrayToString(COUNT1 + COUNT2,
                merge(COUNT1, a1, COUNT2, a2)) << endl;
        }
        {
            int a1[] = {1, 3, 5, 7, 9, 11, 13, 15};
            int a2[] = {2, 4, 6, 8, 10};
            cout << "a1 = " <<
                arrayToString(COUNT1, a1) << endl;
            cout << "a2 = " <<
                arrayToString(COUNT2, a2) << endl;
            cout << "merged = " <<
                arrayToString(COUNT1 + COUNT2,
                merge(COUNT1, a1, COUNT2, a2)) << endl;
        }
        {
            int a1[] = {1, 2, 3, 4, 5};
            int a2[] = {1, 2, 3, 4, 5};
            cout << "a1 = " <<
                arrayToString(COUNT1, a1) << endl;
            cout << "a2 = " <<
                arrayToString(COUNT2, a2) << endl;
            cout << "merged = " <<
                arrayToString(COUNT1 + COUNT2,
                merge(COUNT1, a1, COUNT2, a2)) << endl;
        }
    }

    // Test calcWaterCollected()
    {
        printf("\nTest calcWaterCollected():\n");
        #define NUM_HILLS 17
        int heights[][NUM_HILLS] = {
                {1,0,2,0,3,0,4,0,5,0,4,0,3,0,2,0,1},
                {1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1},
                {1,3,0,7,2,0,9,0,4,3,0,5,6,0,8,0,3}
        };
        int numTests =
            sizeof(heights) / sizeof(int) / NUM_HILLS;
        for (int i = 0; i < numTests; i++) {
            printf("heights = %s\n",
                arrayToString(NUM_HILLS, &heights[i][0]).c_str());
            printf("water collected = %d\n",
                calcWaterCollected(NUM_HILLS,
                                   &heights[i][0]));
        }
    }
}

