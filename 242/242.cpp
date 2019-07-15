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

ʹ�ù�ϣ��ӳ�䣬��һ�������������ϣ��,���ж������ַ��������Ƿ���ͬ������ֱͬ�ӷ���false��Ȼ���s�����е��ַ����ָ���ͳ������������һ����С
Ϊ26�������У���Ϊ��Ŀ���޶��������ַ���ΪСд��ĸ��ɡ�Ȼ������ͳ��t�ַ�����������ֲ�ƥ���򷵻�false��
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
		++m[s[i] - 'a'];//ͳ�ƴ���
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
	cout << "�����ַ���1��" << endl;
	getline(cin, test1);
	cout << "�����ַ���2��" << endl;
	getline(cin, test2);
	cout << isAnagram(test1, test2) << endl;
	system("pause");
	return 0;
}