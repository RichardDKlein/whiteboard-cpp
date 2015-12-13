#include <algorithm>
#include <cstdio>

using namespace std;

size_t stringLength(const char* s);

/**
 * @brief Compare two strings.
 *
 * @param s1 One of the strings.
 * @param s2 The other string.
 * @return +1 if s1 > s2, 0 if s1 == s2, or -1 if s1 < s2.
 */
int stringCompare(const char* s1, const char* s2) {
    size_t len1 = stringLength(s1);
    size_t len2 = stringLength(s2);
    for (size_t i = 0; i < min(len1, len2); i++) {
        char c1 = s1[i];
        char c2 = s2[i];
        if (c1 < c2) {
            return -1;
        } else if (c1 > c2) {
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
    printf("\n");
    printf("Test stringCompare()\n");
    printf("====================\n");

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
        printf("stringCompare(\"%s\", \"%s\") = %d\n",
            s1, s2, stringCompare(s1, s2));
    }
}
