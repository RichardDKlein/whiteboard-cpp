#include <iostream>
#include <string>
#include <vector>

using namespace std;

size_t stringLength(const char* s) {
    const char* p = s;
    while (*p) {
        p++;
    }
    return (p - s);
}

char* stringCopy(const char* s) {
    size_t len = stringLength(s);
    char* copy = new char[len + 1];
    // copy terminating null
    for (size_t i = 0; i < len + 1; i++) {
        copy[i] = s[i];
    }
    return copy;
}

int stringCompare(const char* s1, const char* s2) {
    size_t len1 = stringLength(s1);
    size_t len2 = stringLength(s2);
    for (size_t i = 0; i < min(len1, len2); i++) {
        char c1 = s1[i];
        char c2 = s2[i];
        if (c1 < c2) {
            return -1;
        } else if (c1 > c2) {
            return +1;
        }
    }
    if (len1 < len2) {
        return -1;
    } else if (len1 > len2) {
        return +1;
    } else {
        return 0;
    }
}

#if 0
// Returns the index of the first occurrence of s2 in s1,
// or (size_t)-1 if there is no such occurrence, or if
// s1 or s2 are empty or null.

size_t findSubstring(char* s1, char* s2) {
    if (!s1 || !s2 || !*s1 || !*s2) {
        return (size_t)-1;
    }
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    bool in_s2 = false;
    size_t begin_s2 = 0;
    for (size_t i = 0; i < len1; i++) {
        if (!in_s2) {
            if (s1[i] == s2[0]) {
                if (len2 == 1) {
                    return i;
                }
                in_s2 = true;
                begin_s2 = i;
            }
        } else {
            if (s1[i] == s2[i - begin_s2]) {
                if (i - begin_s2 + 1 == len2) {
                    return begin_s2;
                }
            } else {
                in_s2 = false;
            }
        }
    }
    return (size_t)-1;
}
#endif

char *
strstr(char* str, char* sub) {
    register char *a, *b;

    /* First scan quickly through the two strings looking for a
     * single-character match.  When it's found, then compare the
     * rest of the substring.
     */

    b = sub;
    if (*b == 0) {
    return str;
    }
    for ( ; *str != 0; str++) {
    if (*str != *b) {
        continue;
    }
    a = str;
    while (1) {
        if (*b == 0) {
        return str;
        }
        if (*a++ != *b++) {
        break;
        }
    }
    b = sub;
    }
    return (char *) 0;
}

bool arePermutations(const char* s1, const char* s2) {
    size_t len1 = stringLength(s1);
    size_t len2 = stringLength(s2);
    if (len1 != len2) {
        return false;
    }
    size_t count1[256];
    size_t count2[256];
    for (size_t i = 0; i < len1; i++) {
        char c1 = s1[i];
        char c2 = s2[i];
        count1[(int)c1]++;
        count2[(int)c2]++;
    }
    for (int i = 0; i < 256; i++) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }
    return true;
}

void reverseString(char* s) {
    size_t len = stringLength(s);
    char* beg = s;
    char* end = s + len - 1;
    while (beg < end) {
        char tmp = *beg;
        *beg++ = *end;
        *end-- = tmp;
    }
}

// Reverse each word in a sentence
// without changing the word order

string reverseWords(string s) {
    string sRev;
    int i, iBeginWord = 0;
    bool inWord = false;
    for (i = 0; i < (int)s.length(); i++) {
        char c = s[i];
        if (isspace(c)) {
            if (inWord) {
                // reverse word
                for (int j = i - 1; j >= iBeginWord; j--) {
                    sRev += s[j];
                }
                inWord = false;
            }
            // echo whitespace char
            sRev += c;
        } else { // not whitespace
            if (!inWord) {
                // note beginning of word
                iBeginWord = i;
                inWord = true;
            }
        }
    }
    if (inWord) {
        // reverse word at end of sentence
        for (int j = i - 1; j >= iBeginWord; j--) {
            sRev += s[j];
        }
    }
    return sRev;
}

string insertCharAt(string s, char c, size_t index) {
    string prefix = s.substr(0, index);
    string suffix = s.substr(index);
    return prefix + c + suffix;
}

vector<string> getPermutations(string s) {
    vector<string> perms;
    if (s == "") {
        perms.push_back("");
        return perms;
    }
    char firstChar = s[0];
    string rem = s.substr(1);
    vector<string> remPerms = getPermutations(rem);
    for (auto& remPerm : remPerms) {
        for (size_t i = 0; i <= rem.length(); ++i) {
            string perm = insertCharAt(remPerm, firstChar, i);
            perms.push_back(perm);
        }
    }
    return perms;
}

void testStrings() {
    cout << endl;
    cout << "=============================================" << endl;
    cout << "                   STRINGS                   " << endl;
    cout << "=============================================" << endl;
    cout << endl;
    const char* testStrings[] = {
        "",
        "Hello, world!",
        "!dlrow ,olleH",
        "abcdefghijklmnopqrstuvwxyz"
    };

    // Test stringLength()
    cout << endl << "Test stringLength():" << endl;
    for (auto s : testStrings) {
        cout << "stringLength(\"" << s << "\") = "
             << stringLength(s) << endl;
    }

    // Test stringCopy()
    cout << endl << "Test stringCopy():" << endl;
    for (auto s : testStrings) {
        char* sCopy = stringCopy(s);
        cout << "stringCopy(\"" << s << "\") = " << "\""
             << sCopy << "\"" << endl;
        delete[] sCopy;
    }

    // Test stringCompare()
    cout << endl << "Test stringCompare():" << endl;
    cout << "stringCompare(\"abc\", \"abd\") = "
         << stringCompare("abc", "abd") << endl;
    cout << "stringCompare(\"abd\", \"abc\") = "
         << stringCompare("abd", "abc") << endl;
    cout << "stringCompare(\"abc\", \"abcd\") = "
         << stringCompare("abc", "abcd") << endl;
    cout << "stringCompare(\"abcd\", \"abc\") = "
         << stringCompare("abcd", "abc") << endl;
    cout << "stringCompare(\"abc\", \"abc\") = "
         << stringCompare("abc", "abc") << endl;

#if 0
    // Test findSubstring()
    printf("\nTest findSubstring():\n");
    const char* s1;
    const char* s2;
    const char* fmt = "findSubstring(\"%s\", \"%s\") = %d\n";
    s1 = "abcdefg";
    s2 = "abc";
    printf(fmt, s1, s2, findSubstring(s1, s2));
    s2 = "cde";
    printf(fmt, s1, s2, findSubstring(s1, s2));
    s2 = "efg";
    printf(fmt, s1, s2, findSubstring(s1, s2));
    s2 = "abcdefg";
    printf(fmt, s1, s2, findSubstring(s1, s2));
    s2 = "abcdefghijklmnop";
    printf(fmt, s1, s2, findSubstring(s1, s2));
    s2 = "defghijkl";
    printf(fmt, s1, s2, findSubstring(s1, s2));
    s2 = "x";
    printf(fmt, s1, s2, findSubstring(s1, s2));
    s2 = "xyz";
    printf(fmt, s1, s2, findSubstring(s1, s2));
    s2 = "";
    printf(fmt, s1, s2, findSubstring(s1, s2));
    s2 = NULL;
    printf(fmt, s1, s2, findSubstring(s1, s2));
#endif

    // Test arePermutations()
    cout << endl << "Test arePermutations():" << endl;
    const char* p1 = "Hello, world";
    const char* p2 = "Hello, world!";
    const char* p3 = "!dlrow ,olleH";
    const char* p4 = "!dlroW ,olleH";
    cout << "arePermutations(\"" << p1 << "\", \""
         << p2 << "\") = " <<
         (arePermutations(p1, p2) ? "true" : "false") << endl;
    cout << "arePermutations(\"" << p2 << "\", \""
         << p3 << "\") = " <<
         (arePermutations(p2, p3) ? "true" : "false") << endl;
    cout << "arePermutations(\"" << p3 << "\", \""
         << p4 << "\") = " <<
         (arePermutations(p3, p4) ? "true" : "false") << endl;
    cout << "arePermutations(\"" << p2 << "\", \""
         << p4 << "\") = " <<
         (arePermutations(p2, p4) ? "true" : "false") << endl;

    // Test reverseString()
    cout << endl << "Test reverseString():" << endl;
    for (auto s : testStrings) {
        char* sCopy = stringCopy(s);
        reverseString(sCopy);
        cout << "reverseString(\"" << s << "\") = "
             << "\"" << sCopy << "\"" << endl;
        delete[] sCopy;
    }

    // Test reverseWords()
    cout << endl << "Test reverseWords():" << endl;
    for (auto s : testStrings) {
        string sRev = reverseWords(s);
        cout << "reverseWords(\"" << s << "\") = "
             << "\"" << sRev << "\"" << endl;
    }

    // Test getPermutations()
    cout << endl << "Test getPermutations():" << endl;
    vector<string> perms = getPermutations("crab");
    cout << "getPermutations(\"crab\") returns "
         << perms.size() << " permutations:" << endl;
    for (auto& s : perms) {
        cout << s << endl;
    }
}

