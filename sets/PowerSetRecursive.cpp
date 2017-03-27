#include "Sets.h"
#include "PowerSetRecursive.h"

void testPowerSetRecursive() {
    cout << endl;
    cout << "Test powerSetRecursive():" << endl;
    cout << "=========================" << endl;

    set<char> s;

    s.insert('a');
    s.insert('b');
    s.insert('c');
    s.insert('d');
    s.insert('e');

    cout << "s = ";
    printSet(s);

    set<set<char>> p = powerSetRecursive(s);
    cout << "powerSetRecursive(s) = " << p.size()
         << " subsets:" << endl;
    printPowerSet(p);
}
