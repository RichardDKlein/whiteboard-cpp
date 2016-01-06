#include "Arrays.h"

/**
 * @brief Merge two sorted arrays into a single sorted array.
 *
 * @param v1 One sorted array.
 * @param v2 The other sorted array.
 * @return The merged array.
 */
template<typename T>
vector<T> mergeTwoSortedArrays(list<T>& v1, list<T>& v2) {
    vector<T> merged;
    for (;;) {
        if (v1.empty()) {
            merged.insert(merged.end(), v2.begin(), v2.end());
            break;
        }
        if (v2.empty()) {
            merged.insert(merged.end(), v1.begin(), v1.end());
            break;
        }
        if (v1.front() < v2.front()) {
            merged.push_back(v1.front());
            v1.pop_front();
        } else {
            merged.push_back(v2.front());
            v2.pop_front();
        }
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
        list<int> l1 = arrayToList(COUNT1, a1);
        list<int> l2 = arrayToList(COUNT2, a2);
        cout << "l1 = " << listToString(l1) << endl;
        cout << "l2 = " << listToString(l2) << endl;
        vector<int> merged = mergeTwoSortedArrays(l1, l2);
        cout << "merged = " << vectorToString(merged) << endl;
    }
    {
        int a1[] = {1, 3, 5, 7, 9};
        int a2[] = {2, 4, 6, 8, 10, 12, 14, 16};
        list<int> l1 = arrayToList(COUNT1, a1);
        list<int> l2 = arrayToList(COUNT2, a2);
        cout << "l1 = " << listToString(l1) << endl;
        cout << "l2 = " << listToString(l2) << endl;
        vector<int> merged = mergeTwoSortedArrays(l1, l2);
        cout << "merged = " << vectorToString(merged) << endl;
    }
    {
        int a1[] = {1, 3, 5, 7, 9, 11, 13, 15};
        int a2[] = {2, 4, 6, 8, 10};
        list<int> l1 = arrayToList(COUNT1, a1);
        list<int> l2 = arrayToList(COUNT2, a2);
        cout << "l1 = " << listToString(l1) << endl;
        cout << "l2 = " << listToString(l2) << endl;
        vector<int> merged = mergeTwoSortedArrays(l1, l2);
        cout << "merged = " << vectorToString(merged) << endl;
    }
    {
        int a1[] = {1, 2, 3, 4, 5};
        int a2[] = {1, 2, 3, 4, 5};
        list<int> l1 = arrayToList(COUNT1, a1);
        list<int> l2 = arrayToList(COUNT2, a2);
        cout << "l1 = " << listToString(l1) << endl;
        cout << "l2 = " << listToString(l2) << endl;
        vector<int> merged = mergeTwoSortedArrays(l1, l2);
        cout << "merged = " << vectorToString(merged) << endl;
    }
    }
