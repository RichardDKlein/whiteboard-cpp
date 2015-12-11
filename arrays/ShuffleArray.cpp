#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

static int random(int min, int max);
/**
 * @brief Shuffle an array, as if it represented a deck of cards.
 *
 * @param count The number of elements (ints) in the array to be shuffled.
 * @param deck The array to be shuffled.
 */
void shuffleArray(int count, int deck[]) {
    for (int i = 0; i < count - 1; i++) {
        // pick a random number j in the
        // interval [i + 1, count - 1]
        int min = i + 1;
        int max = count - 1;
        int j = random(min, max);
        // swap cards i and j
        int tmp = deck[i];
        deck[i] = deck[j];
        deck[j] = tmp;
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

string arrayToString(int count, int array[]);

void testShuffleArray() {
    printf("\n");
    printf("Test shuffleArray():\n");
    printf("====================\n");
    #define NUM_CARDS 52
    int deck[NUM_CARDS];
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i] = i;
    }
    printf("Unshuffled deck = %s\n",
        arrayToString(NUM_CARDS, deck).c_str());
    for (int i = 0; i < 10; i++) {
        shuffleArray(NUM_CARDS, deck);
        printf("Shuffled   deck = %s\n",
            arrayToString(NUM_CARDS, deck).c_str());
    }
}
