#pragma once

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int findSubstring(char* s, char* sub);
vector<string> permutationsOfString(const string& s);
void reverseStringInPlace(char* s);
char* reverseWordsInSentence(char* s);
bool stringsArePermutations(const string& s1, const string& s2);

void testFindSubstring();
void testLongestPalindromicSubstring();
void testParseStringIntoWords();
void testPermutationsOfString();
void testReverseStringInPlace();
void testReverseWordsInSentence();
void testStringsArePermutations();
void testTopKStrings();
