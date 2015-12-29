#include "BitManipulation.h"

/**
 * @brief Gets the specified bit in an unsigned int.
 *
 * @param n The unsigned int.
 * @param b The bit # to get (where 0 = the LSB).
 * @return The current value (0 or 1) of the specified bit.
 */
int getBit(unsigned int n, int b) {
    return n & (1 << b) ? 1 : 0;
}

void testGetBit() {
    cout << endl;
    cout << "Test getBit():" << endl;
    cout << "==============" << endl;

    unsigned int n = 0xAAAAAAAA;
    printBits(n);
    for (int i = 0; i < 32; ++i) {
        cout<< "Bit " << i << " = " << getBit(n, i) << endl;
    }
}
