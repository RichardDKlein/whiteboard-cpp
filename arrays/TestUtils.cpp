#include <string>
#include <vector>

using namespace std;

/**
 * @brief Represents an array of ints as a string
 *
 * @param count The number of ints in the array.
 * @param array The array.
 * @return A string representing the array.
 */
string arrayToString(int count, int array[]) {
    string result = "[ ";
    for (int i = 0; i < count; i++) {
        char buf[32];
        sprintf(buf, "%d ", array[i]);
        result += buf;
    }
    result += "]";
    return result;
}

/**
 * @brief Represents a vector of ints as a string
 *
 * @param count The number of ints in the vector.
 * @param v The vector.
 * @return A string representing the vector.
 */
string vectorToString(vector<int> v) {
    string result = "[ ";
    int count = v.size();
    for (int i = 0; i < count; i++) {
        char buf[32];
        sprintf(buf, "%d ", v[i]);
        result += buf;
    }
    result += "]";
    return result;
}

/**
 * @brief Creates a vector from an array of ints
 *
 * @param count The number of ints in the array.
 * @param array The array of ints.
 * @return A vector equivalent to |array|.
 */
vector<int> arrayToVector(int count, int array[]) {
	vector<int> result;
	for (int i = 0; i < count; ++i) {
		result.push_back(array[i]);
	}
	return result;
}
