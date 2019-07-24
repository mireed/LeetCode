/*leetcode 20. Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true
Example 2:
Input: "()[]{}"
Output: true
Example 3:
Input: "(]"
Output: false
Example 4:
Input: "([)]"
Output: false
Example 5:
Input: "{[]}"
Output: true

用一个栈，遍历输入字符串，如果当前字符为左半边括号时，则将其压入栈中，如果遇到右半边括号时，
若此时栈为空，则直接返回false，如不为空，则取出栈顶元素，若为对应的左半边括号，则继续循环，反之返回false
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s) {
	stack<char> st;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			st.push(s[i]);
		}
		else {
			if (st.empty()) {
				return false;
			}
			if (s[i] == ')' && st.top() != '(') {
				return false;
			}
			if (s[i] == ']' && st.top() != '[') {
				return false;
			}
			if (s[i] == '}' && st.top() != '{') {
				return false;
			}
			st.pop();
		}
	}
	return st.empty();
}

int main() {
	string test;
	getline(cin, test);
	cout << isValid(test) << endl;
	system("pause");
	return 0;
}