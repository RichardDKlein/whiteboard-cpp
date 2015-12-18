#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

/**
 * @brief Compute the water collected between the bars of
 * a histogram.
 *
 * @param count The number of histogram bars.
 * @param heights An array specifying the height, in inches,
 * of each histogram bar.
 * @return The amount, in inches, of water collected between
 * the histogram bars.
 */
int histogramWater(int count, int heights[]) {
    int left = 0;
    int right = count - 1;

    int* leftTallest = new int[count];
    int leftMax = -1;
    for (int i = left; i <= right; ++i) {
        if (heights[i] > leftMax) {
            leftMax = heights[i];
        }
        leftTallest[i] = leftMax;
    }
    int* rightTallest = new int[count];
    int rightMax = -1;
    for (int i = right; i >= left; --i) {
        if (heights[i] > rightMax) {
            rightMax = heights[i];
        }
        rightTallest[i] = rightMax;
    }
    int* waterline = new int[count];
    for (int i = left; i <= right; ++i) {
        waterline[i] = min(leftTallest[i], rightTallest[i]);
    }
    int waterCollected = 0;
    for (int i = left; i <= right; i++) {
        if (waterline[i] > heights[i]) {
            waterCollected += (waterline[i] - heights[i]);
        }
    }
    delete[] waterline;
    delete[] rightTallest;
    delete[] leftTallest;

    return waterCollected;
}

string arrayToString(int count, int array[]);

void testHistogramWater() {
    printf("\n");
    printf("Test histogramWater():\n");
    printf("======================\n");
    #define NUM_BARS 17
    int heights[][NUM_BARS] = {
            {1,0,2,0,3,0,4,0,5,0,4,0,3,0,2,0,1},
            {1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1},
            {1,3,0,7,2,0,9,0,4,3,0,5,6,0,8,0,3}
    };
    int numTests = sizeof(heights) / sizeof(int) / NUM_BARS;
    for (int i = 0; i < numTests; i++) {
        printf("heights = %s\n",
            arrayToString(NUM_BARS, &heights[i][0]).c_str());
        printf("water collected = %d\n",
            histogramWater(NUM_BARS, &heights[i][0]));
    }
}
