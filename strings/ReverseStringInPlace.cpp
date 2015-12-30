#include "Strings.h"

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

void testReverseStringInPlace() {
    cout << endl;
    cout << "Test reverseStringInPlace():" << endl;
    cout << "============================" << endl;

    const char* testStrings[] = {
        "",
        "Hello, world!",
        "!dlrow ,olleH",
        "abcdefghijklmnopqrstuvwxyz"
    };

    for (auto& s : testStrings) {
        char* sCopy = stringCopy(s);
        reverseStringInPlace(sCopy);
        cout << "reverseStringInPlace(\"" << s
             << "\") = \"" << sCopy << "\"" << endl;
        delete[] sCopy;
    }
}
