#include "Arrays.h"
#include "ShuffleArray.h"

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
