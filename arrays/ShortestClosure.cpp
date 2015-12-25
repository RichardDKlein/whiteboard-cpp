#include <climits>
#include <cstdio>
#include <list>
#include <vector>

using namespace std;

typedef pair<int, int> Closure;
typedef list<int> LocationList;
typedef vector<LocationList> LocationLists;

template<typename T> LocationLists buildLocationLists(
    const vector<T>& needles, const vector<T>& haystack);
int closureLength(const Closure& closure);
Closure nextCandidate(LocationLists& locLists);

/**
 * @brief Find the shortest closure of needles in a haystack,
 * i.e. the shortest interval in the haystack that contains
 * all the needles.
 */
template<typename T>
Closure shortestClosure(vector<T> needles, vector<T> haystack) {
    LocationLists locLists = buildLocationLists(needles, haystack);
    int haystackLen = haystack.size();
    Closure shortest(0, haystackLen - 1);
    for (;;) {
        Closure candidate = nextCandidate(locLists);
        if (candidate.first < 0) {
            break;
        }
        if (closureLength(candidate) < closureLength(shortest)) {
            shortest = candidate;
        }
    }
    return shortest;
}

template<typename T> LocationLists buildLocationLists(
    const vector<T>& needles, const vector<T>& haystack) {

    int numNeedles = needles.size();
    int haystackLen = haystack.size();

    LocationLists locLists(numNeedles);
    for (int i = 0; i < numNeedles; ++i) {
        T needle = needles[i];
        for (int j = 0; j < haystackLen; ++j) {
            if (haystack[j] == needle) {
                locLists[i].push_back(j);
            }
        }
    }
    return locLists;
}

Closure nextCandidate(LocationLists& locLists) {
    int min = INT_MAX;
    int max = -1;
    for (auto& locList : locLists) {
        if (locList.empty()) {
            return Closure(-1, -1);
        }
        int front = locList.front();
        if (front < min) {
            min = front;
        }
        if (front > max) {
            max = front;
        }
    }
    for (auto& locList : locLists) {
        if (locList.front() == min) {
            locList.pop_front();
            break;
        }
    }
    return Closure(min, max);
}

int closureLength(const Closure& closure) {
    return (closure.second - closure.first + 1);
}

void testShortestClosure() {
    printf("\n");
    printf("Test shortestClosure():\n");
    printf("=======================\n");

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

    Closure shortest = shortestClosure(needles, haystack);

    printf("needles: { ");
    for (auto& needle : needles) {
        printf("%d ", needle);
    }
    printf("}\n");

    printf("haystack: { ");
    int haystackLen = haystack.size();
    for (int i = 0; i < haystackLen; ++i) {
        if (i == shortest.first) {
            printf("[** ");
        }
        printf("%d ", haystack[i]);
        if (i == shortest.second) {
            printf("**] ");
        }
    }
    printf("}\n");

    printf("shortest closure: [%d, %d]\n",
        shortest.first, shortest.second);
}
