#include <cstdio>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Merge two sorted arrays into a single sorted array.
 *
 * @param v1 One sorted array.
 * @param v2 The other sorted array.
 * @return The merged array.
 */
vector<int> mergeTwoSortedArrays(vector<int>& v1, vector<int>& v2) {
    vector<int> result;
    for (;;) {
        if (v1.empty()) {
            for (auto& element : v2) {
                result.push_back(element);
            }
            v2.clear();
            break;
        } else if (v2.empty()) {
            for (auto& element : v1) {
                result.push_back(element);
            }
            v1.clear();
        } else {
            if (v1.front() < v2.front()) {
                result.push_back(v1.front());
                v1.erase(v1.begin());
            } else {
                result.push_back(v2.front());
                v2.erase(v2.begin());
            }
        }
    }
    return result;
}

string arrayToString(int count, int array[]);
vector<int> arrayToVector(int count, int array[]);
string vectorToString(vector<int> v);

void testMergeTwoSortedArrays() {
    printf("\n");
    printf("Test mergeTwoSortedArrays():\n");
    printf("=========================\n");
    #define COUNT1 sizeof(a1)/sizeof(int)
    #define COUNT2 sizeof(a2)/sizeof(int)
    {
        int a1[] = {1, 3, 5, 7, 9};
        int a2[] = {2, 4, 6, 8, 10};
        printf("a1 = %s\n", arrayToString(COUNT1, a1).c_str());
        printf("a2 = %s\n", arrayToString(COUNT2, a2).c_str());
        vector<int> v1 = arrayToVector(COUNT1, a1);
        vector<int> v2 = arrayToVector(COUNT2, a2);
        vector<int> merged = mergeTwoSortedArrays(v1, v2);
        printf("merged = %s\n", vectorToString(merged).c_str());
    }
    {
        int a1[] = {1, 3, 5, 7, 9};
        int a2[] = {2, 4, 6, 8, 10, 12, 14, 16};
        printf("a1 = %s\n", arrayToString(COUNT1, a1).c_str());
        printf("a2 = %s\n", arrayToString(COUNT2, a2).c_str());
        vector<int> v1 = arrayToVector(COUNT1, a1);
        vector<int> v2 = arrayToVector(COUNT2, a2);
        vector<int> merged = mergeTwoSortedArrays(v1, v2);
        printf("merged = %s\n", vectorToString(merged).c_str());
    }
    {
        int a1[] = {1, 3, 5, 7, 9, 11, 13, 15};
        int a2[] = {2, 4, 6, 8, 10};
        printf("a1 = %s\n", arrayToString(COUNT1, a1).c_str());
        printf("a2 = %s\n", arrayToString(COUNT2, a2).c_str());
        vector<int> v1 = arrayToVector(COUNT1, a1);
        vector<int> v2 = arrayToVector(COUNT2, a2);
        vector<int> merged = mergeTwoSortedArrays(v1, v2);
        printf("merged = %s\n", vectorToString(merged).c_str());
    }
    {
        int a1[] = {1, 2, 3, 4, 5};
        int a2[] = {1, 2, 3, 4, 5};
        printf("a1 = %s\n", arrayToString(COUNT1, a1).c_str());
        printf("a2 = %s\n", arrayToString(COUNT2, a2).c_str());
        vector<int> v1 = arrayToVector(COUNT1, a1);
        vector<int> v2 = arrayToVector(COUNT2, a2);
        vector<int> merged = mergeTwoSortedArrays(v1, v2);
        printf("merged = %s\n", vectorToString(merged).c_str());
    }
    }
