#include "Arrays.h"

/**
 * @brief Compute the water collected between the bars of
 * a histogram.
 *
 * @param heights An array specifying the height, in inches,
 * of each histogram bar.
 * @return The amount, in inches, of water collected between
 * the histogram bars.
 */
int histogramWater(const vector<int>& heights) {
    vector<int> leftTallest(heights.size());
    int maxLeft = -1;
    for (int i = 0; i < (int)heights.size(); ++i) {
        maxLeft = max(maxLeft, heights[i]);
        leftTallest[i] = maxLeft;
    }
    vector<int> rightTallest(heights.size());
    int maxRight = -1;
    for (int i = heights.size() - 1; i >= 0; --i) {
        maxRight = max(maxRight, heights[i]);
        rightTallest[i] = maxRight;
    }
    vector<int> waterline(heights.size());
    for (int i = 0; i < (int)heights.size(); ++i) {
        waterline[i] = min(leftTallest[i], rightTallest[i]);
    }
    int waterCollected = 0;
    for (int i = 0; i < (int)heights.size(); ++i) {
        if (waterline[i] > heights[i]) {
            waterCollected += waterline[i] - heights[i];
        }
    }
    return waterCollected;
}

void testHistogramWater() {
    cout << endl;
    cout << "Test histogramWater():" << endl;
    cout << "======================" << endl;

    #define NUM_BARS 17
    int heights[][NUM_BARS] = {
            {1,0,2,0,3,0,4,0,5,0,4,0,3,0,2,0,1},
            {1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1},
            {1,3,0,7,2,0,9,0,4,3,0,5,6,0,8,0,3}
    };
    for (auto& testArray : heights) {
        vector<int> v;
        for (auto n : testArray) {
            v.push_back(n);
        }
        printf("heights = %s\n", vectorToString(v).c_str());
        printf("water collected = %d\n", histogramWater(v));
    }
}
