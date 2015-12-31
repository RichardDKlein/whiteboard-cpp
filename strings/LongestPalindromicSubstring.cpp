#include "Strings.h"
#include "../arrays/Arrays.h"

static Interval longestPalindromeWithCenter(const string& s,
    int center, bool lengthIsOdd);

/**
 * @brief Find the longest palindromic substring in a string.
 *
 * @param s String of interest.
 * @return Pair of indices in |s| representing longest palindromic
 * substring.
 */
Interval longestPalindromicSubstring(string s) {
    Interval result(0, 0);
    int stringLen = s.size();
    for (int i = 1; i < stringLen; ++i) {
        Interval longestOdd = longestPalindromeWithCenter(s, i, true);
        Interval longestEven = longestPalindromeWithCenter(s, i, false);
        if (longestOdd.length() > result.length()) {
            result = longestOdd;
        }
        if (longestEven.length() > result.length()) {
            result = longestEven;
        }
    }
    return result;
}

static Interval longestPalindromeWithCenter(const string& s,
    int center, bool lengthIsOdd) {

    Interval result(center, center);
    int left = center - 1;
    int right = lengthIsOdd ? center + 1 : center;
    int stringLen = s.size();
    while (left >= 0 && right < stringLen && s[left] == s[right]) {
        Interval candidate(left, right);
        if (candidate.length() > result.length()) {
            result = candidate;
        }
        --left;
        ++right;
    }
    return result;
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
