#ifndef STRINGS_H
#define STRINGS_H

#include <iostream>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int findSubstring(char* s, char* sub);
vector<string> permutationsOfString(const string& s);
void reverseStringInPlace(char* s);
char* reverseWordsInSentence(char* s);
int stringCompare(char* s1, char* s2);
char* stringCopy(char* s);
int stringLength(char* s);
bool stringsArePermutations(char* s1, char* s2);

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
