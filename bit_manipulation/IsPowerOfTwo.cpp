#include "BitManipulation.h"

/**
 * @brief Determines whether an unsigned int is a power of 2.
 *
 * @param n The unsigned int.
 * @return |true| if the unsigned int is a power of 2, otherwise |false|.
 */
bool isPowerOfTwo(unsigned int n) {
    return n && !(n & (n - 1));
}

void testIsPowerOfTwo() {
    cout << endl;
    cout << "Test isPowerOfTwo():" << endl;
    cout << "====================" << endl;

    unsigned int n;

    n = 0;
    printBits(n);
    cout << "Is power of 2 = "
         << (isPowerOfTwo(n) ? "true" : "false") << endl;

    n = 1;
    printBits(n);
    cout << "Is power of 2 = "
         << (isPowerOfTwo(n) ? "true" : "false") << endl;

    for (int i = 1; i < 32; ++i) {
        n = 0;
        n = setBit(n, i);
        printBits(n);
        cout << "Is power of 2 = "
             << (isPowerOfTwo(n) ? "true" : "false") << endl;
        n = setBit(n, 0);
        printBits(n);
        cout << "Is power of 2 = "
             << (isPowerOfTwo(n) ? "true" : "false") << endl;
    }
}
