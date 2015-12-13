#include <cstdio>

size_t stringLength(const char* s);

/**
 * @brief Determine whether two strings are permutations
 * of each other.
 *
 * @param s1 One of the strings.
 * @param s2 The other string.
 * @return |true| if the strings are permutations of each
 * other, |false| otherwise.
 */
bool stringsArePermutations(const char* s1, const char* s2) {
    size_t len1 = stringLength(s1);
    size_t len2 = stringLength(s2);
    if (len1 != len2) {
        return false;
    }
    size_t count1[256];
    size_t count2[256];
    for (size_t i = 0; i < 256; ++i) {
        count1[i] = 0;
        count2[i] = 0;
    }
    for (size_t i = 0; i < len1; ++i) {
        unsigned char c1 = s1[i];
        unsigned char c2 = s2[i];
        ++count1[(int)c1];
        ++count2[(int)c2];
    }
    for (int i = 0; i < 256; ++i) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }
    return true;
}

void testStringsArePermutations() {
    printf("\n");
    printf("Test stringsArePermutations()\n");
    printf("=============================\n");

    const char* testStrings[] = {
        "Hello, world",
        "Hello, world!",
        "!dlrow ,olleH",
        "!dlroW ,olleH"
    };

    int numTestStrings = sizeof(testStrings) / sizeof(char*);
    for (int i = 0; i < numTestStrings; ++i) {
        for (int j = i + 1; j < numTestStrings; ++j) {
            const char* s1 = testStrings[i];
            const char* s2 = testStrings[j];
            printf("stringsArePermutations(\"%s\", \"%s\") = %s\n",
                s1, s2,
                stringsArePermutations(s1, s2) ? "true" : "false");
        }
    }
}
