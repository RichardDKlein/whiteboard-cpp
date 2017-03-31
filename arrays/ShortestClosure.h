#pragma once
#include "Arrays.h"

/**
 * Find the shortest closure of needles in a haystack, i.e.
 * the shortest interval in the haystack that contains all
 * the needles.
 */
template<typename T>
class ShortestClosure {
    using LocationList = list<int>;
    using LocationLists = vector<LocationList>;

private:
    vector<T> haystack_;
    vector<T> needles_;
    LocationLists locLists_;
    Interval shortest_;

public:
    ShortestClosure(const vector<T>& haystack, const vector<T>& needles) :
        haystack_(haystack),
        needles_(needles)
    {}

    Interval solve() {
        shortest_ = Interval(0, haystack_.size() - 1);
        buildLocationLists();
        for (;;) {
            Interval candidate = nextCandidate();
            if (!candidate.valid()) {
                break;
            }
            if (candidate.length() < shortest_.length()) {
                shortest_ = candidate;
            }
        }
        return shortest_;
    }

private:
    void buildLocationLists() {
        locLists_ = LocationLists(needles_.size());
        for (int i = 0; i < needles_.size(); ++i) {
            for (int j = 0; j < haystack_.size(); ++j) {
                if (needles_[i] == haystack_[j]) {
                    locLists_[i].push_back(j);
                }
            }
        }
    }

    Interval nextCandidate() {
        int min = INT_MAX;
        int max = -1;
        LocationList* minLocList;
        for (auto& locList : locLists_) {
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
};
