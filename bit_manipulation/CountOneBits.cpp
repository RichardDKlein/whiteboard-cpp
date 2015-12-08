#include <cstdio>

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

void printBits(unsigned int n);
unsigned int toggleBit(unsigned int n, int b);

void testCountOneBits() {
	printf("\n");
    printf("Test countOneBits():\n");
    printf("====================\n");
    unsigned int n = 0;
    for (int i = 0; i < 32; ++i) {
        n = toggleBit(n, i);
        printBits(n);
        printf("Number of 1 bits = %d\n", countOneBits(n));
    }
    for (int i = 0; i < 32; ++i) {
        n = toggleBit(n, i);
        printBits(n);
        printf("Number of 1 bits = %d\n", countOneBits(n));
    }
}
