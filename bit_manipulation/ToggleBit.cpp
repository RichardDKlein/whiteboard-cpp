#include <cstdio>

/**
 * @brief Toggles the specified bit in an unsigned int.
 *
 * @param n The unsigned int.
 * @param b The bit # to toggle (where 0 = the LSB).
 * @return The unsigned int after toggling the bit.
 */
unsigned int toggleBit(unsigned int n, int b) {
    return n ^ (1 << b);
}

void printBits(unsigned int n);

void testToggleBit() {
    printf("\n");
    printf("Test toggleBit():\n");
    printf("=================\n");
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
