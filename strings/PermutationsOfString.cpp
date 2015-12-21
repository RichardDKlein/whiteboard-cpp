#include <cstdio>
#include <string>
#include <vector>

using namespace std;

string insertCharAt(string s, char c, size_t index);

/**
 * @brief Find all permutations of a string.
 *
 * @param s The string of interest.
 * @return Vector containing all permutations of |s|.
 */
vector<string> permutationsOfString(string s) {
    vector<string> perms;
    if (s == "") {
        perms.push_back("");
        return perms;
    }
    char firstChar = s[0];
    string rem = s.substr(1);
    vector<string> remPerms = permutationsOfString(rem);
    for (auto& remPerm : remPerms) {
        for (size_t i = 0; i <= rem.length(); ++i) {
            string perm = insertCharAt(remPerm, firstChar, i);
            perms.push_back(perm);
        }
    }
    return perms;
}

string insertCharAt(string s, char c, size_t index) {
    string prefix = s.substr(0, index);
    string suffix = s.substr(index);
    return prefix + c + suffix;
}

void testPermutationsOfString() {
    printf("\n");
    printf("Test permutationsOfString():\n");
    printf("============================\n");

    const char* testString = "crab";
    vector<string> perms = permutationsOfString(testString);
    printf("permutationsOfString(\"%s\") returns %d permutations:\n",
        testString, perms.size());
    for (auto& perm : perms) {
        printf("\t\"%s\"\n", perm.c_str());
    }
}
