/*leetcode 387. First Unique Character in a String
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:
s = "leetcode"
return 0.
s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters.

用哈希表建立映射然后遍历数组
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s) {
	unordered_map<char, int> m;
	for (char it : s) {
		++m[it];
	}
	for (int i = 0; i < s.size(); ++i) {
		if (m[s[i]] == 1) {
			return i;
		}
	}
	return -1;
}

int main() {
	string test;
	getline(cin, test);
	cout << firstUniqChar(test) << test;
	system("pause");
	return 0;
}