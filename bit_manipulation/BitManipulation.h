#pragma once
#include <iostream>

using namespace std;

int bitDiff(unsigned int m, unsigned int n);
unsigned int clearBit(unsigned int n, int b);
int countOneBits(unsigned int n);
int getBit(unsigned int n, int b);
unsigned int insertBits(unsigned int n, int msb, int lsb,
    unsigned int bits);
bool isPowerOfTwo(unsigned int n);
void printBits(unsigned int n);
unsigned int reverseBits(unsigned int n);
unsigned int setBit(unsigned int n, int b);
unsigned int toggleBit(unsigned int n, int b);

void testBitDiff();
void testClearBit();
void testCountOneBits();
void testGetBit();
void testInsertBits();
void testIsPowerOfTwo();
void testReverseBits();
void testSetBit();
void testToggleBit();

