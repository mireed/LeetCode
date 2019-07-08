/*leetcode 395. Longest Substring with At Least K Repeating Characters
  Find the length of the longest substring T of a given string (consists of lowercase letters only) such that 
every character in T appears no less than k times.

  Example 1:
Input:
s = "aaabb", k = 3
Output:
3
The longest substring is "aaa", as 'a' is repeated 3 times.
  Example 2:
Input:
s = "ababbc", k = 2
Output:
5
The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.

遍历字符串，对于每一个字符，我们都将其视为起点，然后遍历到末尾，我们增加哈希表中字母的出现次数，
如果其小于k，我们将mask的对应位改为1，如果大于等于k，将mask对应位改为0。然后看mask是否为0，是的话就更新res结果，
然后把当前满足要求的子字符串的起始位置j保存到max_idx中，等内层循环结束后，将外层循环变量i赋值为max_idx+1，继续循环直至结束
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int longestSubstring(string s, int k) {
		int res = 0, i = 0, n = s.size();
		while (i + k <= n) {
			int m[26] = { 0 }, mask = 0, max_idx = i;
			for (int j = i; j < n; j++) {
				int t = s[j] - 'a';
				++m[t];
				if (m[t] < k) mask |= (1 << t);
				else mask &= (~(1 << t));
				if (mask == 0) {
					res = max(res, j - i + 1);
					max_idx = j;
				}
			}
			i = max_idx + 1;
		}
		return res;
	}
};

int main() {
	int res, k;
	string str;
	cout << "请输入k值：" << endl;
	cin >> k;
	cout << "请输入字符串：" << endl;
	getline(cin, str);
	Solution t;
	res = t.longestSubstring(str, k);
	cout << res << endl;
	system("pause");
	return 0;
}