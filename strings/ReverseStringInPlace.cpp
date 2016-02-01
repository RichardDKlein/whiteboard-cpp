#include "Strings.h"

/**
 * @brief Reverse a string in place.
 *
 * @param s The string to be reversed.
 */
void reverseStringInPlace(char* s) {
    char* left = s;
    while (*s) {
        ++s;
    }
    char* right = s - 1;
    while (left < right) {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        ++left;
        --right;
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
        char* sCopy = new char[strlen(s) + 1];
        strcpy(sCopy, s);
        reverseStringInPlace(sCopy);
        cout << "reverseStringInPlace(\"" << s
             << "\") = \"" << sCopy << "\"" << endl;
        delete[] sCopy;
    }
}
