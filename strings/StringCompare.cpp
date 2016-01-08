#include "Strings.h"

/**
 * @brief Compare two strings.
 *
 * @param s1 One of the strings.
 * @param s2 The other string.
 * @return +1 if s1 > s2, 0 if s1 == s2, or -1 if s1 < s2.
 */
int stringCompare(char* s1, char* s2) {
    int len1 = stringLength(s1);
    int len2 = stringLength(s2);
    int minLen = min(len1, len2);
    for (int i = 0; i < minLen; ++i) {
        if (s1[i] < s2[i]) {
            return -1;
        } else if (s1[i] > s2[i]) {
            return +1;
        }
    }
    if (len1 < len2) {
        return -1;
    } else if (len1 > len2) {
        return +1;
    } else {
        return 0;
    }
}

void testStringCompare() {
    cout << endl;
    cout << "Test stringCompare():" << endl;
    cout << "=====================" << endl;

    const char* testStrings1[] = {
        "abc",
        "abd",
        "abc",
        "abcd",
        "abc"
    };

    const char* testStrings2[] = {
        "abd",
        "abc",
        "abcd",
        "abc",
        "abc"
    };

    int numTestStrings = sizeof(testStrings1) / sizeof(char*);
    for (int i = 0; i < numTestStrings; ++i) {
        const char* s1 = testStrings1[i];
        const char* s2 = testStrings2[i];
        int c = stringCompare((char*)s1, (char*)s2);
        cout << "stringCompare(\"" << s1 << "\", \""
             << s2 << "\") = " << c << endl;
    }
}
