#include <cstdio>

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

void printBits(unsigned int n);

void testGetBit() {
	printf("\n");
    printf("Test getBit():\n");
    printf("==============\n");
    unsigned int n = 0xAAAAAAAA;
    printBits(n);
    for (int i = 0; i < 32; ++i) {
        printf("Bit %d = %d\n", i, getBit(n, i));
    }
}
