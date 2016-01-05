#include "BitManipulation.h"

/**
 * @brief Insert a contiguous segment of bits into an unsigned int.
 *
 * @param n The unsigned int into which the bits are to be inserted.
 * @param bits The bits to be inserted. It is assumed that the bits
 * of interest occupy the least significant bits of |bits|. The higher
 * order bits will be ignored (and should ideally be set to zero to
 * make the intention clear).
 * @param msb The bit # of the most significant bit in |n| where the
 * bits are to be inserted.
 * @param lsb The bit # of the least significant bit in |n| where the
 * bits are to be inserted.
 */
unsigned int insertBits(
    unsigned int n, unsigned int bits, int msb, int lsb) {

    int numBits = msb - lsb + 1;
    unsigned int mask = ((1 << numBits) - 1) << lsb;
    return (n & ~mask) | (bits << lsb);
}

void testInsertBits() {
    cout << endl;
    cout << "Test insertBits():" << endl;
    cout << "==================" << endl;

    unsigned int n = 0;

    cout << "Destination bits:" << endl;
    printBits(n);
    cout << "Bits to insert:" << endl;
    unsigned int bits = 0x3F;
    printBits(bits);
    n = insertBits(n, bits, 29, 24);
    printBits(n);
}
