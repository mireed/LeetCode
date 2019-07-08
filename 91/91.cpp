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
    建立一维 dp 数组，其中 dp[i] 表示s中前i个字符组成的子串的解码方法的个数，长度比输入数组长多多1，并将 dp[0] 初始化为1。
	现在来找状态转移方程，dp[i] 的值跟之前的状态有着千丝万缕的联系，以例2来分析吧，当 i=1 时，对应s中的字符是 s[0]='2'，
那么只有一种拆分方法，就是2，注意 s[0] 一定不能为0，这样的话无法拆分。当 i=2 时，对应s中的字符是 s[1]='2'，由于 s[1] 不为0，
那么其可以被单独拆分出来，就可以在之前 dp[i-1] 的每种情况下都加上一个单独的2，这样 dp[i] 至少可以有跟 dp[i-1] 一样多的拆分情况，
接下来还要看其能否跟前一个数字拼起来，若拼起来的两位数小于等于26，并且大于等于 10（因为两位数的高位不能是0），那么就可以在之前
dp[i-2] 的每种情况下都加上这个二位数，所以最终 dp[i] = dp[i-1] + dp[i-2]。所以0是个很特殊的存在，若当前位置是0，那么一定无法
单独拆分出来，即不能加上 dp[i-1]，就只能看否跟前一个数字组成大于等于 10 且小于等于 26 的数，能的话可以加上 dp[i-2]，否则就只能
保持为0了。具体的操作步骤是，在遍历的过程中，对每个数字首先判断其是否为0，若是则将 dp[i] 赋为0，若不是，赋上 dp[i-1] 的值，然后
看数组前一位是否存在，如果存在且满足前一位是1，或者和当前位一起组成的两位数不大于 26，则当前 dp[i] 值加上 dp[i - 2]。
最终返回 dp 数组的最后一个值即可
*/

#include <iostream>
#include <vector>
#include <string>
 
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		vector<int> dp(s.size() + 1, 0);//前i个字符组成的子串的解码方法的个数
		if (s.empty() || s[0] == '0') {
			return 0;
		}
		dp[0] = 1;
		for (int i = 1; i < dp.size(); ++i) {
			dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];
			if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {//注意这儿是i-1和i-2，索引是从0开始
				dp[i] += dp[i - 2];
			}
		}
		return dp.back();
		//return dp.at(vec.size()-1);
		// return vec.end() - 1;  end指向末尾元素的下一个元素
		// return vec.rbegin();
	}
};

int main() {
	string str;
	int res;
	cout << "请输入一个字符串： " << endl;
	getline(cin, str);
	Solution t;//调用类的函数
	res = t.numDecodings(str);
	cout << res << endl;
	system("pause");
	return 0;
}