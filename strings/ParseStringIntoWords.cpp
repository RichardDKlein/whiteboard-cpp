#include "Strings.h"

class ParseResult {
private:
    bool success_;
    vector<string> words_;
public:
    ParseResult(bool success, const vector<string>& words) :
        success_(success), words_(words) {}
    bool success() {return success_;}
    vector<string> words() {return words_;}
};

#define EMPTY_VECTOR vector<string>()
#define SUCCESS_EMPTY_STRING ParseResult(true, EMPTY_VECTOR)
#define FAILURE ParseResult(false, EMPTY_VECTOR)

using Dictionary = unordered_set<string>;

/**
 * @brief Parse a string containing no whitespace into its
 * constituent words.
 *
 * @param dict Dictionary of legal words.
 * @param s String to be parsed.
 * @return Constituent words (if parse successful).
 */
ParseResult parseStringIntoWords(const string& s,
    const Dictionary& dict) {

    if (s == "") {
        return SUCCESS_EMPTY_STRING;
    }
    for (int i = 0; i < (int)s.size(); ++i) {
        string firstWord = s.substr(0, i + 1);
        if (dict.count(firstWord) == 0) {
            continue;
        }
        string rem = s.substr(i + 1, string::npos);
        ParseResult remParse = parseStringIntoWords(rem, dict);
        if (!remParse.success()) {
            return FAILURE;
        }
        vector<string> remWords = remParse.words();
        vector<string> words;
        words.push_back(firstWord);
        words.insert(words.end(), remWords.begin(), remWords.end());
        return ParseResult(true, words);
    }
    return FAILURE;
}

void testParseStringIntoWords() {
    cout << endl;
    cout << "Test parseStringIntoWords():" << endl;
    cout << "============================" << endl;

    Dictionary dict;
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
        ParseResult parse = parseStringIntoWords(s, dict);
        cout << "parseStringIntoWords(\"" << s << "\"):" << endl;
        cout << "{" << endl;
        for (const auto& word : parse.words()) {
            cout << "\t\"" << word << "\""  << endl;
        }
        cout << "}" << endl;
    }
}
