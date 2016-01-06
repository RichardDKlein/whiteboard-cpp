#ifndef STRINGS_H
#define STRINGS_H

#include <iostream>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int findSubstring(const char* s, const char* sub);
vector<string> permutationsOfString(const string& s);
void reverseStringInPlace(char* s);
char* reverseWordsInSentence(const char* s);
int stringCompare(const char* s1, const char* s2);
char* stringCopy(const char* s);
int stringLength(const char* s);
bool stringsArePermutations(const string& s1, const string& s2);

void testFindSubstring();
void testLongestPalindromicSubstring();
void testParseStringIntoWords();
void testPermutationsOfString();
void testReverseStringInPlace();
void testReverseWordsInSentence();
void testStringCompare();
void testStringCopy();
void testStringLength();
void testStringsArePermutations();
void testTopKStrings();

#endif // STRINGS_H
