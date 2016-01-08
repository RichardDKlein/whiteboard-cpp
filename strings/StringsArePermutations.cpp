#include "Strings.h"

using Tally = unordered_map<char, int>;

/**
 * @brief Determine whether two strings are permutations
 * of each other.
 *
 * @param s1 One of the strings.
 * @param s2 The other string.
 * @return |true| if the strings are permutations of each
 * other, |false| otherwise.
 */
bool stringsArePermutations(char* s1, char* s2) {
    int len1 = stringLength(s1);
    int len2 = stringLength(s2);
    if (len1 != len2) {
        return false;
    }
    Tally tally1, tally2;
    for (int i = 0; i < len1; ++i) {
        ++tally1[s1[i]];
        ++tally2[s2[i]];
    }
    return tally1 == tally2;
}

void testStringsArePermutations() {
    cout << endl;
    cout << "Test stringsArePermutations():" << endl;
    cout << "==============================" << endl;

    const char* testStrings[] = {
        "Hello, world",
        "Hello, world!",
        "!dlrow ,olleH",
        "!dlroW ,olleH",
        "aabbb",
        "aaabb"
    };

    int numTestStrings = sizeof(testStrings) / sizeof(char*);
    for (int i = 0; i < numTestStrings; ++i) {
        for (int j = i; j < numTestStrings; ++j) {
            const char* s1 = testStrings[i];
            const char* s2 = testStrings[j];
            bool p = stringsArePermutations((char*)s1, (char*)s2);
            cout << "stringsArePermutations(\"" << s1
                 << "\", \"" << s2 << "\") = "
                 << (p ? "true" : "false") << endl;
        }
    }
}
