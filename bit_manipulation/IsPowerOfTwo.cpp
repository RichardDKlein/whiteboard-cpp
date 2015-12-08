#include <cstdio>

/**
 * @brief Determines whether an unsigned int is a power of 2.
 *
 * @param n The unsigned int.
 * @return |true| if the unsigned int is a power of 2, otherwise |false|.
 */
bool isPowerOfTwo(unsigned int n) {
	return n && !(n & (n - 1));
}

void printBits(unsigned int n);
unsigned int setBit(unsigned int n, int b);

void testIsPowerOfTwo() {
	printf("\n");
    printf("Test isPowerOfTwo():\n");
    printf("====================\n");
    for (int i = 0; i < 32; ++i) {
        unsigned int n = 0;
        n = setBit(n, i);
        printBits(n);
        printf("Is power of 2 = %s\n", isPowerOfTwo(n) ?
            "true" : "false");
        n = setBit(n, 0);
        printBits(n);
        printf("Is power of 2 = %s\n", isPowerOfTwo(n) ?
            "true" : "false");
    }
}
