/*leetcode 17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

回溯法中的排列树问题，利用递归DFS
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void helpDFS(string digits, vector<string>& res, string out, int level, vector<string>& dict) {
	if (level == digits.size()) {
		res.push_back(out);
		return;
	}
	string str = dict[digits[level] - '0'];
	for (int i = 0; i < str.size(); ++i) {
		helpDFS(digits, res, out + str[i], level + 1, dict);
	}
}

vector<string> letterCombinations(string digits) {
	if (digits.empty()) {
		return{};
	}
	vector<string> res;
	vector<string> dict {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	helpDFS(digits, res, "", 0, dict);
	return res;
}

int main() {
	vector<string> result;
	string test;
	getline(cin, test);
	result = letterCombinations(test);
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}
	system("pause");
	return 0;
}