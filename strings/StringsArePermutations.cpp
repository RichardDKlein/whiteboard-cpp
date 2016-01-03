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
    if (s1.size() != s2.size()) {
        return false;
    }
    multiset<char> seen1, seen2;
    for (int i = 0; i < (int)s1.size(); ++i) {
        seen1.insert(s1[i]);
        seen2.insert(s2[i]);
    }
    return seen1 == seen2;
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
            bool p = stringsArePermutations(s1, s2);
            cout << "stringsArePermutations(\"" << s1
                 << "\", \"" << s2 << "\") = "
                 << (p ? "true" : "false") << endl;
        }
    }
}
