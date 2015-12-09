#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

/**
 * @brief Compute the water collected between the bars of
 * a histogram.
 *
 * Compute the amount of water (in inches, say) collected
 * in the valleys between 3D histogram bars having given
 * heights (also in inches), after a pitcher of water is
 * poured over the histogram.
 *
 * The algorithm determines the waterline by extending the
 * top of each histogram bar horizontally until it touches
 * the closest bars on the left and right.
 *
 * The time and space complexities are O(n*n) and O(n),
 * respectively.
 *
 * @param count The number of histogram bars.
 * @param heights An array specifying the height, in inches,
 * of each histogram bar.
 * @return The amount, in inches, of water collected between
 * the histogram bars.
 */
int calcWaterCollected(int count, int heights[]) {
    int* waterLine = new int[count];
    memcpy(waterLine, heights, count * sizeof(int));
    int left = 0;
    int right = count - 1;
    for (int i = left; i <= right; i++) {
        if (heights[i] < waterLine[i]) {
            continue; // hill is already underwater
        }
        if (i != left) {
            // find closest taller hill on left
            for (int j = i - 1; j >= left; j--) {
                if (heights[j] > heights[i]) {
                    // found taller hill
                    for (int k = i - 1; k > j; k--) {
                        waterLine[k] = heights[i];
                    }
                    break;
                }
            }
        }
        if (i != right) {
            // find closest taller hill on right
            for (int j = i + 1; j <= right; j++) {
                if (heights[j] > heights[i]) {
                    // found taller hill
                    for (int k = i + 1; k < j; k++) {
                        waterLine[k] = heights[i];
                    }
                    break;
                }
            }
        }
    }
    int waterCollected = 0;
    for (int i = left; i <= right; i++) {
        waterCollected += (waterLine[i] - heights[i]);
    }
    delete[] waterLine;
    return waterCollected;
}

string arrayToString(int count, int array[]);

void testComputeHistogramWater() {
    printf("\n");
    printf("Test computeHistogramWater():\n");
    printf("=============================\n");
    #define NUM_HILLS 17
    int heights[][NUM_HILLS] = {
            {1,0,2,0,3,0,4,0,5,0,4,0,3,0,2,0,1},
            {1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1},
            {1,3,0,7,2,0,9,0,4,3,0,5,6,0,8,0,3}
    };
    int numTests = sizeof(heights) / sizeof(int) / NUM_HILLS;
    for (int i = 0; i < numTests; i++) {
        printf("heights = %s\n",
            arrayToString(NUM_HILLS, &heights[i][0]).c_str());
        printf("water collected = %d\n",
            calcWaterCollected(NUM_HILLS, &heights[i][0]));
    }
}
