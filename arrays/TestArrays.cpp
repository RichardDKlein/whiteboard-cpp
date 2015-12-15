#include <cstdio>

void testHistogramWater();
void testMergeTwoSortedArrays();
void testSearchSortedAndRotatedArray();
void testShuffleArray();
void testSumPairsInSortedArray();
void testSumPairsInUnsortedArray();

/**
 * @brief Test the functions in the "arrays" folder.
 */
void testArrays() {
    printf("\n");
    printf("=============================================\n");
    printf("                   ARRAYS                    \n");
    printf("=============================================\n");

    testHistogramWater();
    testMergeTwoSortedArrays();
    testSearchSortedAndRotatedArray();
    testShuffleArray();
    testSumPairsInSortedArray();
    testSumPairsInUnsortedArray();
}
