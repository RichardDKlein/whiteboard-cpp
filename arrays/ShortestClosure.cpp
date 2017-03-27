#include "Arrays.h"
#include "ShortestClosure.h"

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

    Interval shortest = shortestClosure(haystack, needles);

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
