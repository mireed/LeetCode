/*leetcode 70. Climbing Stairs 
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

斐波拉契数列
*/

#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
	if (n <= 1) {
		return 1;
	}
	vector<int> dp(n);
	dp[0] = 1;
	dp[1] = 2;
	for (int i = 2; i < n; ++i) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	return dp.back();
	//return dp[n - 1];
	//back()函数返回最后一个元素的地址，end()返回尾地址，尾地址不指向任何存储的元素，而是标志vector的结束
}

int main() {
	int n;
	cin >> n;
	cout << climbStairs(n) << endl;
	system("pause");
	return 0;
}