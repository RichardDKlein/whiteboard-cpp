#include "Strings.h"
#include "../arrays/Arrays.h"

static Interval longestAtCenter(const string& s,
    int center, bool lengthIsOdd);

/**
 * @brief Find the longest palindromic substring in a string.
 *
 * @param s String of interest.
 * @return Pair of indices in |s| representing longest palindromic
 * substring.
 */
Interval longestPalindromicSubstring(const string& s) {
    Interval longest(0, 0);
    for (int i = 0; i < (int)s.size(); ++i) {
        Interval longestOdd = longestAtCenter(s, i, true);
        Interval longestEven = longestAtCenter(s, i, false);
        if (longestOdd.length() > longest.length()) {
            longest = longestOdd;
        }
        if (longestEven.length() > longest.length()) {
            longest = longestEven;
        }
    }
    return longest;
}

static Interval longestAtCenter(const string& s,
    int center, bool lengthIsOdd) {

    Interval longest(center, center);
    int left = lengthIsOdd ? center - 1 : center;
    int right = center + 1;
    while (left >= 0 && right < (int)s.size()
            && s[left] == s[right]) {
        longest = Interval(left--, right++);
    }
    return longest;
}

void testLongestPalindromicSubstring() {
    cout << endl;
    cout << "Test longestPalindromicSubstring():" << endl;
    cout << "===================================" << endl;

    string testStrings[] = {
        "now is the time",
        "hello, world!",
        "forgeeksskeegfor",
        "able was i ere i saw elba"
    };

    for (auto& s : testStrings) {
        Interval i = longestPalindromicSubstring(s);
        string p = s.substr(i.left(), i.length());
        cout << "longestPalindromicSubstring(\""
             << s << "\") = \"" << p << "\"" << endl;
    }
}
