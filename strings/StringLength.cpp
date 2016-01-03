#include "Strings.h"

/**
 * @brief Compute the length of a string.
 *
 * @param s The string of interest.
 * @return The length of |s| (excluding terminating null).
 */
int stringLength(const char* s) {
    const char* p = s;
    while (*p) {
        ++p;
    }
    return (p - s);
}

void testStringLength() {
    cout << endl;
    cout << "Test stringLength():" << endl;
    cout << "====================" << endl;

    const char* testStrings[] = {
        "",
        "Hello, world!",
        "!dlrow ,olleH",
        "abcdefghijklmnopqrstuvwxyz"
    };

    for (auto& s : testStrings) {
        size_t len = stringLength(s);
        cout << "stringLength(\"" << s << "\") = " << len << endl;
    }
}
