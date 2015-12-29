#include "BitManipulation.h"

/**
 * @brief Count the number of '1' bits in an unsigned int.
 *
 * @param n The unsigned int.
 * @return The number of '1' bits in |n|.
 */
int countOneBits(unsigned int n) {
    int count = 0;
    while (n) {
        n &= n - 1;
        ++count;
    }
    return count;
}

void testCountOneBits() {
    cout << endl;
    cout << "Test countOneBits():" << endl;
    cout << "====================" << endl;

    unsigned int n = 0;

    for (int i = 0; i < 32; ++i) {
        n = toggleBit(n, i);
        printBits(n);
        cout << "Number of 1 bits = " << countOneBits(n) << endl;
    }

    for (int i = 0; i < 32; ++i) {
        n = toggleBit(n, i);
        printBits(n);
        cout << "Number of 1 bits = " << countOneBits(n) << endl;
    }
}
