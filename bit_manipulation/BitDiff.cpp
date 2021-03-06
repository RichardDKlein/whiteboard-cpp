#include "BitManipulation.h"

/**
 * @brief Determines the bit difference between two unsigned ints,
 * i.e. the number of bits that must be toggled to transform one
 * int into the other.
 *
 * @param m One unsigned int.
 * @param n The other unsigned int.
 * @return The bit difference between |m| and |n|.
 */
int bitDiff(unsigned int m, unsigned int n) {
    return countOneBits(m ^ n);
}

void testBitDiff() {
    cout << endl;
    cout << "Test bitDiff():" << endl;
    cout << "===============" << endl;

    unsigned int m = 0xAAAAAAAA;
    unsigned int n = 0xAAABAACA;

    printBits(m);
    printBits(n);
    cout << "Bit diff = " << bitDiff(m, n) << endl;
}
