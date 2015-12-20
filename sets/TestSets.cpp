#include <cstdio>

void testPowerSetIterative();
void testPowerSetRecursive();

/**
 * @brief Test the functions in the "sets" folder.
 */
void testSets() {
    printf("\n");
    printf("=============================================\n");
    printf("                    SETS                     \n");
    printf("=============================================\n");

    testPowerSetIterative();
    testPowerSetRecursive();
}
