#include "Arrays.h"
#include "MergeTwoSortedArrays.h"

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
