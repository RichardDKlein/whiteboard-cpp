#include "Strings.h"

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
    string firstChar = s.substr(0, 1);
    string rem = s.substr(1, string::npos);
    vector<string> remPerms = permutationsOfString(rem);
    for (auto& remPerm : remPerms) {
        for (int i = 0; i <= (int)remPerm.length(); ++i) {
            string perm = remPerm;
            perm.insert(i, firstChar);
            perms.push_back(perm);
        }
    }
    return perms;
}

void testPermutationsOfString() {
    cout << endl;
    cout << "Test permutationsOfString():" << endl;
    cout << "============================" << endl;

    const char* testString = "abcd";
    vector<string> perms = permutationsOfString(testString);
    cout << "permutationsOfString(\"" << testString
         << "\") returns " << perms.size() << " permutations:"
         << endl;
    for (auto& perm : perms) {
        cout << "\t\"" << perm << "\"" << endl;
    }
}
