/*leetcode 125. Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:
Input: "race a car"
Output: false

只需要建立两个指针，left和right, 分别从字符的开头和结尾处开始遍历整个字符串，如果遇到非字母数字的字符就跳过，继续往下找，直到找到下一个字母
数字或者结束遍历，如果遇到大写字母，就将其转为小写。等左右指针都找到字母数字时，比较这两个字符，若相等，则继续比较下面两个分别找到的字母数字，
若不相等，直接返回false.时间复杂度为O(n),
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