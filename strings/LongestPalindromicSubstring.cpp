#include "Strings.h"
#include "../arrays/Arrays.h"

/**
 * Find the longest palindromic substring in a string.
 */
class LongestPalindromicSubstring {
private:
    string s_;

public:
    LongestPalindromicSubstring(const string& s) : s_(s) {}

    Interval solve() {
        Interval longest(0, 0);
        for (int i = 0; i < (int)s_.length(); ++i) {
            Interval longestOdd = longestAtCenter(i, true);
            Interval longestEven = longestAtCenter(i, false);
            if (longestOdd.valid()
                    && longestOdd.length() > longest.length()) {
                longest = longestOdd;
            }
            if (longestEven.valid()
                    && longestEven.length() > longest.length()) {
                longest = longestEven;
            }
        }
        return longest;
    }

private:
    Interval longestAtCenter(int center, bool lengthIsOdd) {
        Interval longest(-1, -1);
        int left = lengthIsOdd ? center - 1 : center;
        int right = center + 1;
        while (left >= 0 && right < (int)s_.length()
                && s_[left] == s_[right]) {
            longest = Interval(left--, right++);
        }
        return longest;
    }
};

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
        LongestPalindromicSubstring longestPalindromicSubstring(s);
        Interval i = longestPalindromicSubstring.solve();
        string p = s.substr(i.left(), i.length());
        cout << "longestPalindromicSubstring(\""
             << s << "\") = \"" << p << "\"" << endl;
    }
}
