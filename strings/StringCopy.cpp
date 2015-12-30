#include "Strings.h"

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
    cout << endl;
    cout << "Test stringCopy():" << endl;
    cout << "==================" << endl;

    const char* testStrings[] = {
        "",
        "Hello, world!",
        "!dlrow ,olleH",
        "abcdefghijklmnopqrstuvwxyz"
    };

    for (auto& s : testStrings) {
        char* sCopy = stringCopy(s);
        cout << "stringCopy(\"" << s << "\") = \""
             << sCopy << "\"" << endl;
        delete[] sCopy;
    }
}
