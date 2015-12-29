#include "BitManipulation.h"

/**
 * @brief Clears the specified bit in an unsigned int.
 *
 * @param n The unsigned int.
 * @param b The bit # to clear (where 0 = the LSB).
 * @return The unsigned int after clearing the bit.
 */
unsigned int clearBit(unsigned int n, int b) {
    return n & ~(1 << b);
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
