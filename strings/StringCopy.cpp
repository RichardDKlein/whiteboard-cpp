#include "Strings.h"

/**
 * @brief Copy a string.
 *
 * @param s The string of interest.
 * @return A copy of |s|.
 */
char* stringCopy(const char* s) {
    int len = stringLength(s);
    char* copy = new char[len + 1];
    copy[len] = '\0';
    for (int i = 0; i < len; ++i) {
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
