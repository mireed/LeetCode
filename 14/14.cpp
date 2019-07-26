/*letcode Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: ["flower","flow","flight"]
Output: "fl"
Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:
All given inputs are in lowercase letters a-z.

将单词上下排好，则相当于一个各行长度有可能不相等的二维数组，遍历顺序和一般的横向逐行遍历不同，而是采用纵向逐列遍历，在遍历的过程中，如果
某一行没有了，说明其为最短的单词，因为共同前缀的长度不能长于最短单词，所以此时返回已经找出的共同前缀。我们每次取出第一个字符串的某一个位置的
单词，然后遍历其他所有字符串的对应位置看是否相等，如果有不满足的直接返回res，如果都相同，则将当前字符存入结果，继续检查下一个位置的字符
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	if (strs.empty()) {
		return "";
	}
	string res = "";
	for (int j = 0; j < strs[0].size(); ++j) {
		char c = strs[0][j];
		for (int i = 1; i < strs.size(); ++i) {
			if (strs[i][j] != c) {
				return res;
			}
		}
		res.push_back(c);
	}
	return res;
}

int main() {
	vector<string> test;
	string temp, result;
	while (getline(cin, temp)) {
		test.push_back(temp);
	}
	result = longestCommonPrefix(test);
	cout << result << endl;
	system("pause");
	return 0;
}