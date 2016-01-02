#include "Arrays.h"

/**
 * @brief Merge two sorted arrays into a single sorted array.
 *
 * @param v1 One sorted array.
 * @param v2 The other sorted array.
 * @return The merged array.
 */
template<typename T>
vector<T> mergeTwoSortedArrays(vector<T>& v1, vector<T>& v2) {
    vector<T> merged;
    for (;;) {
        if (v1.empty()) {
            merged.insert(merged.end(), v2.begin(), v2.end());
            return merged;
        }
        if (v2.empty()) {
            merged.insert(merged.end(), v1.begin(), v1.end());
            return merged;
        }
        if (v1.front() < v2.front()) {
            merged.push_back(v1.front());
            v1.erase(v1.begin());
        }
        merged.push_back(v2.front());
        v2.erase(v2.begin());
    }
    return merged;
}

void testMergeTwoSortedArrays() {
    cout << endl;
    cout << "Test mergeTwoSortedArrays():" << endl;
    cout << "============================" << endl;

    #define COUNT1 sizeof(a1)/sizeof(int)
    #define COUNT2 sizeof(a2)/sizeof(int)
    {
        int a1[] = {1, 3, 5, 7, 9};
        int a2[] = {2, 4, 6, 8, 10};
        vector<int> v1 = arrayToVector(COUNT1, a1);
        vector<int> v2 = arrayToVector(COUNT2, a2);
        cout << "v1 = " << vectorToString(v1) << endl;
        cout << "v2 = " << vectorToString(v2) << endl;
        vector<int> merged = mergeTwoSortedArrays(v1, v2);
        cout << "merged = " << vectorToString(merged) << endl;
    }
    {
        int a1[] = {1, 3, 5, 7, 9};
        int a2[] = {2, 4, 6, 8, 10, 12, 14, 16};
        vector<int> v1 = arrayToVector(COUNT1, a1);
        vector<int> v2 = arrayToVector(COUNT2, a2);
        cout << "v1 = " << vectorToString(v1) << endl;
        cout << "v2 = " << vectorToString(v2) << endl;
        vector<int> merged = mergeTwoSortedArrays(v1, v2);
        cout << "merged = " << vectorToString(merged) << endl;
    }
    {
        int a1[] = {1, 3, 5, 7, 9, 11, 13, 15};
        int a2[] = {2, 4, 6, 8, 10};
        vector<int> v1 = arrayToVector(COUNT1, a1);
        vector<int> v2 = arrayToVector(COUNT2, a2);
        cout << "v1 = " << vectorToString(v1) << endl;
        cout << "v2 = " << vectorToString(v2) << endl;
        vector<int> merged = mergeTwoSortedArrays(v1, v2);
        cout << "merged = " << vectorToString(merged) << endl;
    }
    {
        int a1[] = {1, 2, 3, 4, 5};
        int a2[] = {1, 2, 3, 4, 5};
        vector<int> v1 = arrayToVector(COUNT1, a1);
        vector<int> v2 = arrayToVector(COUNT2, a2);
        cout << "v1 = " << vectorToString(v1) << endl;
        cout << "v2 = " << vectorToString(v2) << endl;
        vector<int> merged = mergeTwoSortedArrays(v1, v2);
        cout << "merged = " << vectorToString(merged) << endl;
    }
    }
