#include <cstdio>

int countOneBits(unsigned int n);

/**
 * @brief Insert a contiguous segment of bits into an unsigned int.
 *
 * @param n The unsigned int into which the bits are to be inserted.
 * @param msb The bit # of the most significant bit in |n| where the
 * bits are to be inserted.
 * @param lsb The bit # of the least significant bit in |n| where the
 * bits are to be inserted.
 * @param bits The bits to be inserted. It is assumed that the bits
 * of interest occupy the least significant bits of |bits|. The higher
 * order bits will be ignored (and should ideally be set to zero to
 * make the intention clear).
 */
unsigned int insertBits(unsigned int n, int msb, int lsb,
                        unsigned int bits) {
    int len = msb - lsb + 1;
    unsigned int mask = ((1 << len) - 1) << lsb;
    return (n & ~mask) | (bits << lsb);
}

void printBits(unsigned int n);

void testInsertBits() {
    printf("\n");
    printf("Test insertBits():\n");
    printf("==================\n");
    unsigned int n = 0;
    printf("Destination bits:\n");
    printBits(n);
    printf("Bits to insert:\n");
    unsigned int m = 0x3F;
    printBits(m);
    n = insertBits(n, 29, 24, m);
    printBits(n);
}