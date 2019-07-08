/*leetcode 91 Decode Ways
  A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

  Example 1:
Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
  Example 2:
Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

  Dynamci Programming:
    ����һά dp ���飬���� dp[i] ��ʾs��ǰi���ַ���ɵ��Ӵ��Ľ��뷽���ĸ��������ȱ��������鳤���1������ dp[0] ��ʼ��Ϊ1��
	��������״̬ת�Ʒ��̣�dp[i] ��ֵ��֮ǰ��״̬����ǧ˿���Ƶ���ϵ������2�������ɣ��� i=1 ʱ����Ӧs�е��ַ��� s[0]='2'��
��ôֻ��һ�ֲ�ַ���������2��ע�� s[0] һ������Ϊ0�������Ļ��޷���֡��� i=2 ʱ����Ӧs�е��ַ��� s[1]='2'������ s[1] ��Ϊ0��
��ô����Ա�������ֳ������Ϳ�����֮ǰ dp[i-1] ��ÿ������¶�����һ��������2������ dp[i] ���ٿ����и� dp[i-1] һ����Ĳ�������
��������Ҫ�����ܷ��ǰһ������ƴ��������ƴ��������λ��С�ڵ���26�����Ҵ��ڵ��� 10����Ϊ��λ���ĸ�λ������0������ô�Ϳ�����֮ǰ
dp[i-2] ��ÿ������¶����������λ������������ dp[i] = dp[i-1] + dp[i-2]������0�Ǹ�������Ĵ��ڣ�����ǰλ����0����ôһ���޷�
������ֳ����������ܼ��� dp[i-1]����ֻ�ܿ����ǰһ��������ɴ��ڵ��� 10 ��С�ڵ��� 26 �������ܵĻ����Լ��� dp[i-2]�������ֻ��
����Ϊ0�ˡ�����Ĳ��������ǣ��ڱ����Ĺ����У���ÿ�����������ж����Ƿ�Ϊ0�������� dp[i] ��Ϊ0�������ǣ����� dp[i-1] ��ֵ��Ȼ��
������ǰһλ�Ƿ���ڣ��������������ǰһλ��1�����ߺ͵�ǰλһ����ɵ���λ�������� 26����ǰ dp[i] ֵ���� dp[i - 2]��
���շ��� dp ��������һ��ֵ����
*/

#include <iostream>
#include <vector>
#include <string>
 
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		vector<int> dp(s.size() + 1, 0);//ǰi���ַ���ɵ��Ӵ��Ľ��뷽���ĸ���
		if (s.empty() || s[0] == '0') {
			return 0;
		}
		dp[0] = 1;
		for (int i = 1; i < dp.size(); ++i) {
			dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];
			if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {//ע�������i-1��i-2�������Ǵ�0��ʼ
				dp[i] += dp[i - 2];
			}
		}
		return dp.back();
		//return dp.at(vec.size()-1);
		// return vec.end() - 1;  endָ��ĩβԪ�ص���һ��Ԫ��
		// return vec.rbegin();
	}
};

int main() {
	string str;
	int res;
	cout << "������һ���ַ����� " << endl;
	getline(cin, str);
	Solution t;//������ĺ���
	res = t.numDecodings(str);
	cout << res << endl;
	system("pause");
	return 0;
}