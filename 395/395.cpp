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

�����ַ���������ÿһ���ַ������Ƕ�������Ϊ��㣬Ȼ�������ĩβ���������ӹ�ϣ������ĸ�ĳ��ִ�����
�����С��k�����ǽ�mask�Ķ�Ӧλ��Ϊ1��������ڵ���k����mask��Ӧλ��Ϊ0��Ȼ��mask�Ƿ�Ϊ0���ǵĻ��͸���res�����
Ȼ��ѵ�ǰ����Ҫ������ַ�������ʼλ��j���浽max_idx�У����ڲ�ѭ�������󣬽����ѭ������i��ֵΪmax_idx+1������ѭ��ֱ������
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
	cout << "������kֵ��" << endl;
	cin >> k;
	cout << "�������ַ�����" << endl;
	getline(cin, str);
	Solution t;
	res = t.longestSubstring(str, k);
	cout << res << endl;
	system("pause");
	return 0;
}