#include "BitManipulation.h"

/**
 * @brief Toggles the specified bit in an unsigned int.
 *
 * @param n The unsigned int.
 * @param bit The bit # to toggle (where 0 = the LSB).
 * @return The unsigned int after toggling the bit.
 */
unsigned int toggleBit(unsigned int n, int bit) {
    return n ^ (1 << bit);
}

void testToggleBit() {
    cout << endl;
    cout << "Test toggleBit():" << endl;
    cout << "=================" << endl;

    unsigned int n = 0;

    for (int i = 0; i < 32; ++i) {
        n = toggleBit(n, i);
        printBits(n);
    }
    for (int i = 0; i < 32; ++i) {
        n = toggleBit(n, i);
        printBits(n);
    }
}
