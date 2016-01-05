#include "BitManipulation.h"

/**
 * @brief Sets the specified bit in an unsigned int.
 *
 * @param n The unsigned int.
 * @param bit The bit # to set (where 0 is the LSB).
 * @return The unsigned int after setting the bit.
 */
unsigned int setBit(unsigned int n, int bit) {
    return n | (1 << bit);
}

void testSetBit() {
    cout << endl;
    cout << "Test setBit():" << endl;
    cout << "==============" << endl;

    unsigned int n = 0;
    for (int i = 0; i < 32; ++i) {
        n = setBit(n, i);
        printBits(n);
    }
}
