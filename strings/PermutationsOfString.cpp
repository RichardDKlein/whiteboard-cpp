#include "Strings.h"

string insertCharAt(string s, char c, size_t index);

/**
 * @brief Find all permutations of a string.
 *
 * @param s The string of interest.
 * @return Vector containing all permutations of |s|.
 */
vector<string> permutationsOfString(const string& s) {
    vector<string> perms;
    if (s == "") {
        perms.push_back("");
        return perms;
    }
    char firstChar = s[0];
    string rem = s.substr(1, string::npos);
    vector<string> remPerms = permutationsOfString(rem);
    for (auto& remPerm : remPerms) {
        for (int i = 0; i <= (int)remPerm.size(); ++i) {
            string perm = insertCharAt(remPerm, firstChar, i);
            perms.push_back(perm);
        }
    }
    return perms;
}

string insertCharAt(string s, char c, size_t index) {
    string prefix = s.substr(0, index);
    string suffix = s.substr(index, string::npos);
    return prefix + c + suffix;
}

void testPermutationsOfString() {
    cout << endl;
    cout << "Test permutationsOfString():" << endl;
    cout << "============================" << endl;

    const char* testString = "crab";
    vector<string> perms = permutationsOfString(testString);
    cout << "permutationsOfString(\"" << testString
         << "\") returns " << perms.size() << " permutations:"
         << endl;
    for (auto& perm : perms) {
        cout << "\t\"" << perm << "\"" << endl;
    }
}
