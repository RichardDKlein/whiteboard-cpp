#include <cstdio>

size_t stringLength(const char* s);

/**
 * @brief Reverse each word in a sentence without changing
 * the word order.
 *
 * @param s The sentence of interest.
 * @return A copy of |s| with each word reversed.
 */
char* reverseWordsInSentence(const char* s) {
    size_t len = stringLength(s);
    char* result = new char[len + 1];
    result[len] = '\0';
    char* r = result;
    while (*s != '\0') {
        if (*s == ' ') {
            *r++ = *s++;
            continue;
        }
        const char* tmp = s;
        while (*s != ' ' && *s != '\0') {
            s++;
        }
        for (const char* p = s - 1; p >= tmp; p--) {
            *r++ = *p;
        }
    }
    return result;
}

void testReverseWordsInSentence() {
    printf("\n");
    printf("Test reverseWordsInSentence()\n");
    printf("=============================\n");

    const char* testStrings[] = {
        "Now is the time",
        "  for all good men  ",
        "to come to the aid of their country."
    };

    int numTestStrings = sizeof(testStrings) / sizeof(char*);
    for (int i = 0; i < numTestStrings; ++i) {
        const char* s = testStrings[i];
        char* r = reverseWordsInSentence(s);
        printf("reverseWordsInSentence(\"%s\") = \"%s\"\n", s, r);
        delete[] r;
    }
}
