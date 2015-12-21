#include <cstdio>

size_t stringLength(const char* s);

/**
 * @brief Copy a string.
 *
 * @param s The string of interest.
 * @return A copy of |s|.
 */
char* stringCopy(const char* s) {
    size_t len = stringLength(s);
    char* copy = new char[len + 1];
    // copy terminating null
    for (size_t i = 0; i < len + 1; ++i) {
        copy[i] = s[i];
    }
    return copy;
}

void testStringCopy() {
    printf("\n");
    printf("Test stringCopy():\n");
    printf("==================\n");

    const char* testStrings[] = {
        "",
        "Hello, world!",
        "!dlrow ,olleH",
        "abcdefghijklmnopqrstuvwxyz"
    };

    for (auto& s : testStrings) {
        char* sCopy = stringCopy(s);
        printf("stringCopy(\"%s\") = \"%s\"\n", s, sCopy);
        delete[] sCopy;
    }
}
