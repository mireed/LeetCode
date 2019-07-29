/*leetcode 28. Implement strStr()
Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

KMP算法
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int strStr(string original, string pattern) {
	if (original.size() == 0) {
		return -1;
	}
	if (pattern.size() == 0) {
		return 0;
	}
	vector<int> next = get_next(pattern);
	int i = 0, j = 0, l1 = original.size(), l2 = pattern.size();
	while (i < l1 && j < l2) {
		if (j == -1 || original[i] == pattern[j]) {
			++i;
			++j;
		}
		else {
			j = next[j];
		}
	}
	if (j == pattern.size()) {
		return i - j;
	}
	else {
		return -1;
	}
}

vector<int> get_next(string s) {
	vector<int> next( s.size(), 0 );
	next[0] = -1;
	int i = 0, j = -1;//s[j]表示前缀，s[i]表示后缀
	while (i < s.size() - 1) {
		if (j == -1 || s[i] == s[j]) {
			++i;
			++j;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
	return next;
}

int main() {
	string test1, test2;
	getline(cin, test1);
	getline(cin, test2);
	cout << strStr(test1, test2) << endl;
	system("pause");
	return 0;
}