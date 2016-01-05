#include "BitManipulation.h"

/**
 * @brief Clears the specified bit in an unsigned int.
 *
 * @param n The unsigned int.
 * @param bit The bit # to clear (where 0 = the LSB).
 * @return The unsigned int after clearing the bit.
 */
unsigned int clearBit(unsigned int n, int bit) {
    return n & ~(1 << bit);
}

void testClearBit() {
    cout << endl;
    cout << "Test clearBit():" << endl;
    cout << "================" << endl;

    unsigned int n = (unsigned) -1;
    for (int i = 0; i < 32; ++i) {
        n = clearBit(n, i);
        printBits(n);
    }
}
