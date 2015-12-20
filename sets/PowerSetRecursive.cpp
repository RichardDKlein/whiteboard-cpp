#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

/**
 * @brief Return the power set of a set, i.e. the set of all subsets
 * of that set, using recursion.
 *
 * @param s The set of interest.
 * @return The power set of |s|.
 */
template<typename T>
set<set<T>> powerSetRecursive(const set<T>& s) {
	set<set<T>> result;
	if (s.empty()) {
		set<T> emptySet;
		result.insert(emptySet);
		return result;
	}
	set<T> s1 = s;
	T first = *s1.begin();
	s1.erase(s1.begin());
	set<set<T>> remPowerSet = powerSetRecursive(s1);
	result = remPowerSet;
	for (auto subset : remPowerSet) {
		subset.insert(first);
		result.insert(subset);
	}
	return result;
}

template<typename T> void printSet(set<T> s);
template<typename T> void printPowerSet(set<set<T>> p);

void testPowerSetRecursive() {
	printf("\n");
	printf("Test powerSetRecursive():\n");
	printf("=========================\n");

	set<char> s;

	s.insert('a');
	s.insert('b');
	s.insert('c');
	s.insert('d');
	s.insert('e');

	cout << "s = ";
	printSet(s);

	set<set<char>> p = powerSetRecursive(s);
	cout << "powerSetRecursive(s) = " << p.size() << " subsets:" << endl;
	printPowerSet(p);
}

template<typename T>
void printSet(set<T> s) {
	cout << "{ ";
	for (const auto& elt : s) {
		cout << elt << " ";
	}
	cout << "}" << endl;
}

template<typename T>
void printPowerSet(set<set<T>> p) {
	cout << "{" << endl;
	for (const auto& s : p) {
		cout << "\t";
		printSet(s);
	}
	cout << "}" << endl;
}
