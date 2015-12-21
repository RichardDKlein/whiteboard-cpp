#include <cstdio>

/**
 * @brief Find a substring in a string.
 *
 * @param s The string of interest.
 * @param sub The substring to find.
 * @return Index of first occurrence of |sub| in |s|,
 * or (size_t) -1 if there is no occurrence.
 */
size_t findSubstring(const char* s, const char* sub) {
    if (*sub == '\0') {
        return 0;
    }
    const char* save = s;
    while (*s != '\0') {
        if (*s != *sub) {
            ++s;
            continue;
        }
        const char* a = s + 1;
        const char* b = sub + 1;
        while (1) {
            if (*b == '\0') {
                return s - save;
            }
            if (*a != *b) {
                ++s;
                break;
            }
            ++a;
            ++b;
        }
    }
    return (size_t) -1;
}

void testFindSubstring() {
    printf("\n");
    printf("Test findSubstring():\n");
    printf("=====================\n");

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
        printf("findSubstring(\"%s\", \"%s\") = %d\n",
            testString, sub, findSubstring(testString, sub));
    }
}
