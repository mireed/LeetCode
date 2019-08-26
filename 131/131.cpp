/*leetcode 131. Palindrome Partitioning
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

Example:
Input: "aab"
Output:
[
["aa","b"],
["a","a","b"]
]

回溯法，DFS遍历
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPalindrome(string s, int start, int end) {
	while (start < end) {
		if (s[start] != s[end]) {
			return false;
		}
		start++;
		end--;
	}
	return true;
}

void helpDFS(vector<vector<string>>& res, string s, int start, vector<string>&out) {
	if (s.empty()) {
		res.push_back(out);
		return;
	}
	if (start == s.size()) {
		res.push_back(out);
		return;
	}
	for (int i = start; i < s.size(); ++i) {
		if (!isPalindrome(s, start, i)) {
			continue;
		}
		out.push_back(s.substr(start, i - start + 1));//从下标为start开始，截取i-start+1长度的子字符串
		helpDFS(res, s, i + 1, out);
		out.pop_back();
	}
}

vector<vector<string>> partition(string s) {
	vector<vector<string>> res;
	vector<string> out;
	helpDFS(res, s, 0, out);
	return res;
}

int main() {
	vector<vector<string>> result;
	string test;
	getline(cin, test);
	result = partition(test);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j) {
			cout << result[i][j] << endl;
		}
	}
	system("pause");
	return 0;
}