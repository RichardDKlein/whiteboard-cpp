#pragma once

#include <cfloat>
#include <climits>
#include <cmath>
#include <list>
#include <unordered_map>
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
    Interval() : left_(0), right_(0) {}
    int left() {return left_;}
    int right() {return right_;}
    int length() {return right_ - left_ + 1;}
    bool valid() {return left_ >= 0 && right_ >= 0 && right_ >= left_;}
};

void testHistogramWater();
void testLinesThruPoints();
void testMergeTwoSortedArrays();
void testSearchSorted2dArray();
void testSearchSortedAndRotatedArray();
void testShortestClosure();
void testShuffleArray();
void testSumPairsInSortedArray();
void testSumPairsInUnsortedArray();
