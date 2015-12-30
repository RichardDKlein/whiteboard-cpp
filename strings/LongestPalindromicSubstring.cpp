#include "Strings.h"

pair<int, int>
longestPalindromeWithCenter(const string& s, int center, bool lengthIsOdd);

/**
 * @brief Find the longest palindromic substring in a string.
 *
 * @param s String of interest.
 * @return Pair of indices in |s| representing longest palindromic
 * substring.
 */
pair<int, int> longestPalindromicSubstring(string s) {
    pair<int, int> result(0, 0);
    int resultLen = 1;
    int stringLen = s.size();
    for (int i = 1; i < stringLen; ++i) {
        pair<int, int> longestOdd = longestPalindromeWithCenter(s, i, true);
        pair<int, int> longestEven = longestPalindromeWithCenter(s, i, false);
        int longestOddLen = longestOdd.second - longestOdd.first + 1;
        int longestEvenLen = longestEven.second - longestEven.first + 1;
        if (longestOddLen > resultLen) {
            result = longestOdd;
            resultLen = longestOddLen;
        }
        if (longestEvenLen > resultLen) {
            result = longestEven;
            resultLen = longestEvenLen;
        }
    }
    return result;
}

/**
 * @brief Find the longest odd- or even-length palindromic substring
 * having a given center.
 *
 * @param s String of interest.
 * @param center Index in |s| of center of palindromic substring.
 * @param lengthIsOdd |true| if the palindrome length is to be odd,
 * |false| if even.
 * @return Pair of indices in |s| representing the longest such
 * palindromic substring.
 */
pair<int, int>
longestPalindromeWithCenter(const string& s, int center, bool lengthIsOdd) {
    pair<int, int> result(0, 0);
    int low = center - 1;
    int high = lengthIsOdd ? center + 1 : center;
    int stringLen = s.size();
    while (low >= 0 && high < stringLen && s[low] == s[high]) {
        if ((high - low + 1) > (result.second - result.first + 1)) {
            result.first = low;
            result.second = high;
        }
        --low;
        ++high;
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
        pair<int, int> i = longestPalindromicSubstring(s);
        string p = s.substr(i.first, i.second - i.first + 1);
        cout << "longestPalindromicSubstring(\""
             << s << "\") = \"" << p << "\"" << endl;
    }
}
