#include <cstdio>

/**
 * @brief Compute the length of a string.
 *
 * @param s The string of interest.
 * @return The length of |s| (excluding terminating null).
 */
size_t stringLength(const char* s) {
    const char* p = s;
    while (*p) {
        p++;
    }
    return (p - s);
}

void testStringLength() {
    printf("\n");
    printf("Test stringLength()\n");
    printf("===================\n");

    const char* testStrings[] = {
        "",
        "Hello, world!",
        "!dlrow ,olleH",
        "abcdefghijklmnopqrstuvwxyz"
    };

    for (auto& s : testStrings) {
        printf("stringLength(\"%s\") = %d\n", s, stringLength(s));
    }
}
