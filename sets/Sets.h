#ifndef SETS_H
#define SETS_H

#include <cmath>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>

using namespace std;

#include "TestUtils.h"

template<typename T> set<set<T>> powerSetIterative(const set<T>& s);
template<typename T> set<set<T>> powerSetRecursive(const set<T>& s);

void testPowerSetIterative();
void testPowerSetRecursive();

#endif // #ifndef SETS_H
