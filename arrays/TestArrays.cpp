#include <cstdio>

void testComputeHistogramWater();
void testFindPairsUsingHashTable();
void testFindPairsUsingNoExtraMemory();
void testMergeTwoSortedArrays();
void testSearchSortedAndRotatedArray();
void testShuffleArray();

/**
 * @brief Test the functions in the "arrays" folder.
 */
void testArrays() {
	printf("\n");
	printf("=============================================\n");
	printf("                   ARRAYS                    \n");
	printf("=============================================\n");

	testComputeHistogramWater();
	testFindPairsUsingHashTable();
	testFindPairsUsingNoExtraMemory();
	testMergeTwoSortedArrays();
	testSearchSortedAndRotatedArray();
	testShuffleArray();
}
