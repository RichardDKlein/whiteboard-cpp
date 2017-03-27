#include "PowerSetIterative.h"
#include "../bit_manipulation/BitManipulation.h"
#include "Sets.h"

void testPowerSetIterative() {
    cout << endl;
    cout << "Test powerSetIterative():" << endl;
    cout << "=========================" << endl;

    set<char> s;

    s.insert('a');
    s.insert('b');
    s.insert('c');
    s.insert('d');
    s.insert('e');

    cout << "s = ";
    printSet(s);

    set<set<char>> p = powerSetIterative(s);
    cout << "powerSetIterative(s) = " << p.size()
         << " subsets:" << endl;
    printPowerSet(p);
}
