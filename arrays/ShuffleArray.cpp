#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

static int random(int min, int max);

/**
 * @brief Shuffle an array, as if it represented a deck of cards.
 *
 * @param deck The array to be shuffled.
 */
void shuffleArray(vector<int>& v) {
    int count = v.size();
    for (int i = 0; i < count - 1; i++) {
        int min = i + 1;
        int max = count - 1;
        int j = random(min, max);

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
    return rand() % (max - min + 1) + min;
}

string vectorToString(vector<int> v);

void testShuffleArray() {
    printf("\n");
    printf("Test shuffleArray():\n");
    printf("====================\n");
    #define NUM_CARDS 52
    vector<int> deck(NUM_CARDS);
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i] = i;
    }
    printf("Unshuffled deck = %s\n", vectorToString(deck).c_str());
    for (int i = 0; i < 10; i++) {
        shuffleArray(deck);
        printf("Shuffled   deck = %s\n",
            vectorToString(deck).c_str());
    }
}
