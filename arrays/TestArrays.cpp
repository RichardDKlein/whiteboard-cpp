#include <cstdio>

void testHistogramWater();
void testMergeTwoSortedArrays();
void testSearchSorted2dArray();
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
    testSearchSorted2dArray();
    testSearchSortedAndRotatedArray();
    testShuffleArray();
    testSumPairsInSortedArray();
    testSumPairsInUnsortedArray();
}
