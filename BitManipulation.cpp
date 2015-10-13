#include <bitset>
#include <iostream>

using namespace std;

unsigned int setBit(unsigned int n, int b) {
    return n | (1 << b);
}

unsigned int clearBit(unsigned int n, int b) {
    return n & ~(1 << b);
}

unsigned int toggleBit(unsigned int n, int b) {
    return n ^ (1 << b);
}

int getBit(unsigned int n, int b) {
    return n & (1 << b) ? 1 : 0;
}

int countOneBits(unsigned int n) {
    int count = 0;
    while (n) {
        n &= n - 1;
        ++count;
    }
    return count;
}

bool isPowerOfTwo(unsigned int n) {
    return countOneBits(n) == 1;
}

int bitDiff(unsigned int m, unsigned int n) {
    return countOneBits(m ^ n);
}

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

unsigned int insertBits(unsigned int n, int msb, int lsb,
                        unsigned int bits) {
    int len = msb - lsb + 1;
    unsigned int mask = ((1 << len) - 1) << lsb;
    return (n & ~mask) | (bits << lsb);
}

void printBits(unsigned int n) {
    bitset<32> bits(n);
    cout << bits << endl;
}

void testBitManipulation() {
	cout << endl;
	cout << "=============================================" << endl;
	cout << "               BIT MANIPULATION              " << endl;
	cout << "=============================================" << endl;
	cout << endl;
    unsigned int m, n;

    // Test printBits()
    printf("\nTest printBits():\n");
    printBits(0xAAAAAAAA);

    // Test setBit()
    printf("\nTest setBit():\n");
    n = 0;
    for (int i = 0; i < 32; ++i) {
        n = setBit(n, i);
        printBits(n);
    }

    // Test clearBit()
    printf("\nTest clearBit():\n");
    n = (unsigned) -1;
    for (int i = 0; i < 32; ++i) {
        n = clearBit(n, i);
        printBits(n);
    }

    // Test getBit()
    printf("\nTest getBit():\n");
    n = 0xAAAAAAAA;
    printBits(n);
    for (int i = 0; i < 32; ++i) {
        printf("Bit %d = %d\n", i, getBit(n, i));
    }

    // Test toggleBit()
    printf("\nTest toggleBit():\n");
    n = 0;
    for (int i = 0; i < 32; ++i) {
        n = toggleBit(n, i);
        printBits(n);
    }
    for (int i = 0; i < 32; ++i) {
        n = toggleBit(n, i);
        printBits(n);
    }

    // Test countOneBits()
    printf("\nTest countOneBits():\n");
    n = 0;
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

    // Test isPowerOfTwo()
    printf("\nTest isPowerOfTwo():\n");
    for (int i = 0; i < 32; ++i) {
        n = 0;
        n = setBit(n, i);
        printBits(n);
        printf("Is power of 2 = %s\n", isPowerOfTwo(n) ?
            "true" : "false");
        ++n;
        printBits(n);
        printf("Is power of 2 = %s\n", isPowerOfTwo(n) ? 
            "true" : "false");
    }

    // Test bitDiff()
    printf("\nTest bitDiff():\n");
    m = 0xAAAAAAAA;
    n = 0xAAABAACA;
    printBits(m);
    printBits(n);
    printf("Bit diff = %d\n", bitDiff(m, n));

    // Test reverseBits()
    printf("\nTest reverseBits():\n");
    n = 0xB77BEFDF;
    printBits(n);
    n = reverseBits(n);
    printf("Reversed:\n");
    printBits(n);

    // Test insertBits()
    printf("\nTest insertBits():\n");
    n = 0;
    printf("Destination bits:\n");
    printBits(n);
    printf("Bits to insert:\n");
    m = 0x3F;
    printBits(m);
    n = insertBits(n, 29, 24, m);
    printBits(n);
}
