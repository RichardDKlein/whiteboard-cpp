#include "Strings.h"

/**
 * @brief Reverse each word in a sentence without changing
 * the word order.
 *
 * @param s The sentence of interest.
 * @return A copy of |s| with each word reversed.
 */
string reverseWordsInSentence(const string& s) {
    string rev(s.size(), ' ');
    int i = 0;
    while (i < (int)s.size()) {
        if (s[i] == ' ') {
            rev[i] = s[i];
            ++i;
            continue;
        }
        int iBeginWord = i;
        while (i < (int)s.size() && s[i] != ' ') {
            ++i;
        }
        int iEndWord = i - 1;
        int j = iBeginWord;
        int k = iEndWord;
        while (j <= iEndWord) {
            rev[j++] = s[k--];
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
        "  for all good men  ",
        "to come to the aid of their country."
    };

    int numTestStrings = sizeof(testStrings) / sizeof(char*);
    for (int i = 0; i < numTestStrings; ++i) {
        string s = testStrings[i];
        string r = reverseWordsInSentence(s);
            cout << "reverseWordsInSentence(\"" << s
                 << "\") = \"" << r << "\"" << endl;
    }
}
