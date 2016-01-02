#include "Arrays.h"

using LocationList = list<int>;
using LocationLists = vector<LocationList>;

template<typename T> static LocationLists buildLocationLists(
    const vector<T>& needles, const vector<T>& haystack);
static Interval nextCandidate(LocationLists& locLists);

/**
 * @brief Find the shortest closure of needles in a haystack,
 * i.e. the shortest interval in the haystack that contains
 * all the needles.
 */
template<typename T>
Interval shortestClosure(vector<T> needles, vector<T> haystack) {
    Interval shortest(0, haystack.size() - 1);
    LocationLists locLists = buildLocationLists(needles, haystack);
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
        const vector<T>& needles, const vector<T>& haystack) {

    LocationLists locLists(needles.size());
    for (int i = 0; i < needles.size(); ++i) {
        for (int j = 0; j < haystack.size(); ++j) {
            if (haystack[j] == needles[i]) {
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

void testShortestClosure() {
    cout << endl;
    cout << "Test shortestClosure():" << endl;
    cout << "=======================" << endl;

    int testNeedles[] = {
        1, 5, 9
    };

    int testHaystack[] = {
        7, 5, 9, 0, 2, 1, 3, 5, 7, 9, 1, 1, 5, 8, 8, 9, 7
    };

    vector<int> needles;
    for (auto& needle : testNeedles) {
        needles.push_back(needle);
    }

    vector<int> haystack;
    for (auto& h : testHaystack) {
        haystack.push_back(h);
    }

    Interval shortest = shortestClosure(needles, haystack);

    cout << "needles: { ";
    for (auto& needle : needles) {
        cout << needle << " ";
    }
    cout << "}" << endl;

    cout << "haystack: { ";
    int haystackLen = haystack.size();
    for (int i = 0; i < haystackLen; ++i) {
        if (i == shortest.left()) {
            cout << "[** ";
        }
        cout << haystack[i] << " ";
        if (i == shortest.right()) {
            cout << "**] ";
        }
    }
    cout << "}" << endl;

    cout << "shortest closure: [" << shortest.left() << ", "
         << shortest.right() << "]" << endl;
}
