/*leetcode 10. Regular Expression Matching
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:
s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.

Example 1:
Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:
Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:
Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:
Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:
Input:
s = "mississippi"
p = "mis*is*p*."
Output: false

分类讨论、回溯法DFS递归
*/

#include <iostream>
#include <string>

using namespace std;

bool isMatch(string s, string p) {
	if (p.empty()) {
		if (s.empty()) {
			return true;
		}
		else {
			return false;
		}
	}
	if (p.size() == 1) {
		return (s.size() == 1 && (p[0] == s[0] || p[0] == '.'));
	}
	if (p[1] != '*') {
		if (s.empty()) {
			return false;
		}
		return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
	}
	while (!s.empty() && (p[0] == s[0] || p[0] == '.')) {
		if (isMatch(s, p.substr(2))) {//假设此时的星号的作用是让前面的字符出现0次，验证是否匹配
			return true;
		}
		s = s.substr(1);
	}
	return isMatch(s, p.substr(2));
}

int main() {
	string test1, test2;
	getline(cin, test1);
	getline(cin, test2);
	cout << isMatch(test1, test2) << endl;
	system("pause");
	return 0;
}