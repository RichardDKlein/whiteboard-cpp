#include <cstdio>

size_t stringLength(const char* s);

/**
 * @brief Reverse a string in place.
 *
 * @param s The string to be reversed.
 */
void reverseStringInPlace(char* s) {
    size_t len = stringLength(s);
    char* beg = s;
    char* end = s + len - 1;
    while (beg < end) {
        char tmp = *beg;
        *beg++ = *end;
        *end-- = tmp;
    }
}

char* stringCopy(const char* s);

void testReverseStringInPlace() {
    printf("\n");
    printf("Test reverseStringInPlace():\n");
    printf("============================\n");

    const char* testStrings[] = {
        "",
        "Hello, world!",
        "!dlrow ,olleH",
        "abcdefghijklmnopqrstuvwxyz"
    };

    for (auto& s : testStrings) {
        char* sCopy = stringCopy(s);
        reverseStringInPlace(sCopy);
        printf("reverseStringInPlace(\"%s\") = \"%s\"\n",
            s, sCopy);
        delete[] sCopy;
    }
}
