#pragma once
#include "Arrays.h"

using LocationList = list<int>;
using LocationLists = vector<LocationList>;

template<typename T> static LocationLists buildLocationLists(
    const vector<T>& haystack, const vector<T>& needles);
static Interval nextCandidate(LocationLists& locLists);

/**
 * @brief Find the shortest closure of needles in a haystack,
 * i.e. the shortest interval in the haystack that contains
 * all the needles.
 */
template<typename T>
Interval shortestClosure(const vector<T>& haystack,
                         const vector<T>& needles) {

    Interval shortest(0, haystack.size() - 1);
    LocationLists locLists = buildLocationLists(haystack, needles);
    for (;;) {
        Interval candidate = nextCandidate(locLists);
        if (!candidate.valid()) {
            break;
        }
        if (candidate.length() < shortest.length()) {
            shortest = candidate;
        }
    }
    return shortest;
}

template<typename T>
static LocationLists buildLocationLists(
        const vector<T>& haystack, const vector<T>& needles) {

    LocationLists locLists(needles.size());
    for (int i = 0; i < needles.size(); ++i) {
        for (int j = 0; j < haystack.size(); ++j) {
            if (needles[i] == haystack[j]) {
                locLists[i].push_back(j);
            }
        }
    }
    return locLists;
}

static Interval nextCandidate(LocationLists& locLists) {
    int min = INT_MAX;
    int max = -1;
    LocationList* minLocList;
    for (auto& locList : locLists) {
        if (locList.empty()) {
            return Interval(-1, -1);
        }
        int front = locList.front();
        if (front < min) {
            min = front;
            minLocList = &locList;
        }
        if (front > max) {
            max = front;
        }
    }
    minLocList->pop_front();
    return Interval(min, max);
}
