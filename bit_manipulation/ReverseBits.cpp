#include "BitManipulation.h"

/**
 * @brief Reverse the bits in an unsigned int.
 *
 * @param n The unsigned int to be reversed.
 * @return The unsigned int that results when the
 * bits of |n| are reversed.
 */
unsigned int reverseBits(unsigned int n) {
    int bitsPerInt = sizeof(n) * 8;
    int rev = 0;
    for (int i = 0; i < bitsPerInt - 1; ++i) {
        rev |= n & 1;
        rev <<= 1;
        n >>= 1;
    }
    rev |= n & 1;
    return rev;
}

void testReverseBits() {
    cout << endl;
    cout << "Test reverseBits():" << endl;
    cout << "===================" << endl;

    unsigned int n = 0xB77BEFDF;

    printBits(n);
    n = reverseBits(n);
    printf("Reversed:\n");
    printBits(n);
}
