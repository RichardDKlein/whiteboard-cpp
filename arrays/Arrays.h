#ifndef ARRAYS_H
#define ARRAYS_H

#include <climits>
#include <list>
#include <unordered_set>
#include <vector>
#include "TestUtils.h"

using namespace std;

class Interval {
private:
    int left_;
    int right_;
public:
    Interval(int left, int right) : left_(left), right_(right) {}
    int left() {return left_;}
    int right() {return right_;}
    int length() {return right_ - left_ + 1;}
    bool valid() {return left_ >= 0 && right_ >= 0 && right_ >= left_;}
};

int histogramWater(const vector<int>& v);
template<typename T> vector<T> mergeTwoSortedArrays(
    vector<T>& v1, vector<T>& v2);
template<typename T> int searchSortedAndRotatedArray(
    const vector<T>& v, const T& target);
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
