#include "Strings.h"

/**
 * @brief Reverse each word in a sentence without changing
 * the word order.
 *
 * @param s The sentence of interest.
 * @return A copy of |s| with each word reversed.
 */
char* reverseWordsInSentence(char* s) {
    int len = strlen(s);
    char* rev = new char[len + 1];
    rev[len] = 0;
    char* r = rev;
    while (*s) {
        if (*s == ' ') {
            *r++ = *s++;
            continue;
        }
        char* beginWord = s;
        while (*s && (*s != ' ')) {
            ++s;
        }
        char* p = s - 1; // end of word
        while (p >= beginWord) {
            *r++ = *p--;
        }
     }
     return rev;
}

void testReverseWordsInSentence() {
    cout << endl;
    cout << "Test reverseWordsInSentence():" << endl;
    cout << "==============================" << endl;

    const char* testStrings[] = {
        "Now is the time",
        " for all good men   ",
        "to come to the aid of their country."
    };

    int numTestStrings = sizeof(testStrings) / sizeof(char*);
    for (int i = 0; i < numTestStrings; ++i) {
        char* s = (char*)testStrings[i];
        char* r = reverseWordsInSentence(s);
            cout << "reverseWordsInSentence(\"" << s
                 << "\") = \"" << r << "\"" << endl;
    }
}
