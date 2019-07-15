/*leetcode 242. Valid Anagram
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true
Example 2:
Input: s = "rat", t = "car"
Output: false

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

使用哈希表映射，用一个数组来代替哈希表,先判断两个字符串长度是否相同，不相同直接返回false。然后把s中所有的字符出现个数统计起来，存入一个大小
为26的数组中，因为题目中限定了输入字符串为小写字母组成。然后再来统计t字符串，如果发现不匹配则返回false。
*/

#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string s, string t) {
	if (s.size() != t.size()) {
		return false;
	}
	int m[26] = { 0 };
	for (int i = 0; i < s.size(); ++i) {
		++m[s[i] - 'a'];//统计次数
	}
	for (int i = 0; i < t.size(); ++i) {
		if (--m[t[i] - 'a'] < 0) {
			return false;
		}
	}
	return true;
}

int main() {
	string test1, test2;
	cout << "输入字符串1：" << endl;
	getline(cin, test1);
	cout << "输入字符串2：" << endl;
	getline(cin, test2);
	cout << isAnagram(test1, test2) << endl;
	system("pause");
	return 0;
}