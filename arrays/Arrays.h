#ifndef ARRAYS_H
#define ARRAYS_H

#include <climits>
#include <list>
#include <set>
#include <vector>

using namespace std;

#include "TestUtils.h"

int histogramWater(const vector<int>& v);
template<typename T> vector<T> mergeTwoSortedArrays(
    vector<T>& v1, vector<T>& v2);
template<typename T> int searchSortedAndRotatedArray(
    const vector<T>& v, T target);
template<typename T> void shuffleArray(vector<T>& v);

void testHistogramWater();
void testMergeTwoSortedArrays();
void testSearchSorted2dArray();
void testSearchSortedAndRotatedArray();
void testShortestClosure();
void testShuffleArray();
void testSumPairsInSortedArray();
void testSumPairsInUnsortedArray();

#endif // #ifndef ARRAYS_H
