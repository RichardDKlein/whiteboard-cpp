#include <bitset>
#include <iostream>

using namespace std;

void printBits(unsigned int n) {
    bitset<32> bits(n);
    cout << bits << endl;
}
