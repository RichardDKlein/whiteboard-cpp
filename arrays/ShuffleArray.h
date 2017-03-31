#pragma once
#include "Arrays.h"

/**
 * Shuffle an array, as if it represented a deck of cards.
 */
template <typename T>
class ShuffleArray {
private:
	/** Array to be shuffled. */
	vector<T> v_;

	/** @brief Return a random int in a given closed interval [min, max]. */
	static int random(int min, int max) {
	    int range = max - min + 1;
	    return (rand() % range) + min;
	}

public:
	ShuffleArray(const vector<T>& v) : v_(v) {
        srand((time(nullptr))); // seed the random number generator
	}

	vector<T> shuffle() {
	    for (int i = 0; i < v_.size() - 1; ++i) {
	        int j = random(i + 1, v_.size() - 1);
	        swap(v_[i], v_[j]);
	    }
	    return v_;
	}
};
