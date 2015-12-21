#include <cstdio>
#include <set>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Parse a string containing no whitespace into its
 * constituent words.
 *
 * @param dict Dictionary of legal words.
 * @param s String to be parsed.
 * @return A pair showing the result of the parse. The first
 * component is a flag indicating whether the parse was successful.
 * The second component is a vector containing the constituent
 * strings of |s|.
 */
pair<bool, vector<string>>
parseStringIntoWords(const set<string>& dict, const string& s) {
    pair<bool, vector<string>> result;
    vector<string> emptyVector;
    pair<bool, vector<string>> failure(false, emptyVector);
    pair<bool, vector<string>> emptyString(true, emptyVector);

    int stringLen = s.size();
    if (stringLen == 0) {
        return emptyString;
    }
    for (int i = 0; i < stringLen; ++i) {
        string firstWord = s.substr(0, i + 1);
        if (dict.count(firstWord) > 0) {
            string rem = s.substr(i + 1, string::npos);
            pair<bool, vector<string>> remWords =
                parseStringIntoWords(dict, rem);
            if (!remWords.first) {
                return failure;
            } else {
                result.first = true;
                result.second.push_back(firstWord);
                for (const auto& remWord : remWords.second) {
                    result.second.push_back(remWord);
                }
                return result;
            }
        }
    }
    return failure;
}

void testParseStringIntoWords() {
    printf("\n");
    printf("Test parseStringIntoWords():\n");
    printf("============================\n");

    set<string> dict;
    dict.insert("now");
    dict.insert("is");
    dict.insert("the");
    dict.insert("time");
    dict.insert("for");
    dict.insert("all");
    dict.insert("good");
    dict.insert("men");
    dict.insert("to");
    dict.insert("come");
    dict.insert("aid");
    dict.insert("of");
    dict.insert("his");
    dict.insert("country");

    const string testStrings[] = {
        "nowisthetimeforallgoodmentocometotheaidofhiscountry",
        "nowisthetimeforallgoodmenntocometotheaidofhiscountry"
    };

    for (const auto& s : testStrings) {
        pair<bool, vector<string>> words = parseStringIntoWords(dict, s);
        printf("parseStringIntoWords(\"%s\"):\n", s.c_str());
        printf("{\n");
        for (const auto& word : words.second) {
            printf("\t\"%s\"\n", word.c_str());
        }
        printf("}\n");
    }
}
