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

�����������źã����൱��һ�����г����п��ܲ���ȵĶ�ά���飬����˳���һ��ĺ������б�����ͬ�����ǲ����������б������ڱ����Ĺ����У����
ĳһ��û���ˣ�˵����Ϊ��̵ĵ��ʣ���Ϊ��ͬǰ׺�ĳ��Ȳ��ܳ�����̵��ʣ����Դ�ʱ�����Ѿ��ҳ��Ĺ�ͬǰ׺������ÿ��ȡ����һ���ַ�����ĳһ��λ�õ�
���ʣ�Ȼ��������������ַ����Ķ�Ӧλ�ÿ��Ƿ���ȣ�����в������ֱ�ӷ���res���������ͬ���򽫵�ǰ�ַ������������������һ��λ�õ��ַ�
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