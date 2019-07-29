/*leetcode 125. Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:
Input: "race a car"
Output: false

ֻ��Ҫ��������ָ�룬left��right, �ֱ���ַ��Ŀ�ͷ�ͽ�β����ʼ���������ַ����������������ĸ���ֵ��ַ������������������ң�ֱ���ҵ���һ����ĸ
���ֻ��߽������������������д��ĸ���ͽ���תΪСд��������ָ�붼�ҵ���ĸ����ʱ���Ƚ��������ַ�������ȣ�������Ƚ����������ֱ��ҵ�����ĸ���֣�
������ȣ�ֱ�ӷ���false.ʱ�临�Ӷ�ΪO(n),
*/

#include <iostream>
#include <string>

using namespace std;

class solution {
public:
	bool isPalindrome(string s) {
		int left = 0, right = s.size() - 1;
		while (left < right) {
			if (!isAlphaNum(s[left])) {
				left++;
			}
			else if (!isAlphaNum(s[right])) {
				right--;
			}
			else if ((s[left] + 32 - 'a') % 32 != (s[right] + 32 - 'a') % 32) {
				return false;
			}
			else {
				++left;
				--right;
			}
		}
		return true;
	}
	bool isAlphaNum(char &ch) {
		if (ch >= 'a' || ch <= 'z') {
			return true;
		}
		if (ch >= 'A' || ch <= 'Z') {
			return true;
		}
		if (ch >= '0' || ch <= '9') {
			return true;
		}
		return false;
	}
};

int main() {
	string test;
	getline(cin, test);
	solution s;
	cout << s.isPalindrome(test) << endl;
	system("pause");
	return 0;
}