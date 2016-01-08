#include "Strings.h"

/**
 * @brief Find a substring in a string.
 *
 * @param s The string of interest.
 * @param sub The substring to find.
 * @return Index of first occurrence of |sub| in |s|,
 * or -1 if there is no occurrence.
 */
int findSubstring(char* s, char* sub) {
    if (*sub == '\0') {
        return 0;
    }
    char* s0 = s;
    while (*s) {
        if (*s != *sub) {
            ++s;
            continue;
        }
        char* a = s + 1;
        char* b = sub + 1;
        for (;;) {
            if (*b == '\0') {
                return s - s0;
            }
            if (*a != *b) {
                ++s;
                break;
            }
            ++a;
            ++b;
        }
    }
    return -1;
}

void testFindSubstring() {
    cout << endl;
    cout << "Test findSubstring():" << endl;
    cout << "=====================" << endl;

    const char* testString = "alfalfa romeo";
    const char* testSubstrings[] = {
        "alfa",
        "rome",
        "alfa romeo",
        "alfa romeos",
        "alfalfa romeo",
        "alfalfa romeos",
        "x",
        ""
    };

    int numTestSubstrings = sizeof(testSubstrings) / sizeof(char*);
    for (int i = 0; i < numTestSubstrings; ++i) {
        const char* sub = testSubstrings[i];
        int index = findSubstring((char*)testString, (char*)sub);
        cout << "findSubstring(\"" << testString
             << "\", \"" << sub << "\") = " << index << endl;
    }
}
