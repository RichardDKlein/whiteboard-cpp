#include "Arrays.h"

static int random(int min, int max);

/**
 * @brief Shuffle an array, as if it represented a deck of cards.
 *
 * @param v The array to be shuffled.
 */
template<typename T>
void shuffleArray(vector<T>& v) {
    for (int i = 0; i < v.size() - 1; i++) {
        int j = random(i + 1, v.size() - 1);
        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }
}

/**
 * @brief Generates a random integer in a given range.
 *
 * @param min The lower bound of the range.
 * @param max The upper bound of the range.
 * @return A random integer in the closed interval [min, max].
 */
static int random(int min, int max) {
    static bool firstTime = true;
    if (firstTime) {
        srand((time(nullptr)));
        firstTime = false;
    }
    int range = max - min + 1;
    return (rand() % range) + min;
}

void testShuffleArray() {
    cout << endl;
    cout << "Test shuffleArray():" << endl;
    cout << "====================" << endl;

    #define NUM_CARDS 52
    vector<int> deck(NUM_CARDS);
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i] = i;
    }

    cout << "Unshuffled deck = " << vectorToString(deck) << endl;
    for (int i = 0; i < 10; i++) {
        shuffleArray(deck);
        cout << "Shuffled   deck = "
             << vectorToString(deck) << endl;
    }
}
