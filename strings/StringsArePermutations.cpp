#include "Strings.h"

/**
 * @brief Determine whether two strings are permutations
 * of each other.
 *
 * @param s1 One of the strings.
 * @param s2 The other string.
 * @return |true| if the strings are permutations of each
 * other, |false| otherwise.
 */
bool stringsArePermutations(const string& s1, const string& s2) {
    string s1Sorted = s1;
    sort(s1Sorted.begin(), s1Sorted.end());
    string s2Sorted = s2;
    sort(s2Sorted.begin(), s2Sorted.end());

    return s1Sorted == s2Sorted;
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
            string s1 = testStrings[i];
            string s2 = testStrings[j];
            bool p = stringsArePermutations(s1, s2);
            cout << "stringsArePermutations(\"" << s1
                 << "\", \"" << s2 << "\") = "
                 << (p ? "true" : "false") << endl;
        }
    }
}
