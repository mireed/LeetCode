/*leetcode 198. House Robber
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only 
constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically 
contact the police if two adjacent houses were broken into on the same night.Given a list of non-negative integers representing the
amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:
Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

法1：动态规划Dynamic Programming，维护一个一位数组dp，其中dp[i]表示到i位置时不相邻数能形成的最大和，拿一个例子来分析一下，比如说nums为
{3, 2, 1, 5}，首先dp[0]=3，由于3比2大，所以我们抢第一个房子的3，当前房子的2不抢，所以dp[1]=3，由于不能抢相邻的，可以用再前面的一个的dp值
加上当前的房间值，和当前房间的前面一个dp值比较，取较大值当做当前dp值，所以我们可以得到状态转移方程dp[i] = max(num[i] + dp[i - 2],dp[i - 1])
, 由此看出需要初始化dp[0]和dp[1]，其中dp[0]即为num[0]，dp[1]此时应该为max(num[0], num[1])

法2：核心思想还是用DP，分别维护两个变量robEven和robOdd，顾名思义，robEven就是要抢偶数位置的房子，robOdd就是要抢奇数位置的房子。所以在遍历房子
数组时，如果是偶数位置，那么robEven就要加上当前数字，然后和robOdd比较，取较大的来更新robEven。robEven组成的值并不是只由偶数位置的数字，只是
当前要抢偶数位置而已。同理，当奇数位置时，robOdd加上当前数字和robEven比较，取较大值来更新robOdd，这种按奇偶分别来更新的方法，可以保证组成最大
和的数字不相邻，最后别忘了在robEven和robOdd种取较大值返回
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//法1
int rob1(vector<int>& nums) {
	if (nums.size() <= 1) {
		if (nums.empty()) {
			return 0;
		}
		else {
			return nums[0];
		}
	}
	vector<int> dp{ nums[0], max(nums[0], nums[1]) };
	for (int i = 2; i < nums.size(); ++i) {
		dp.push_back(max(dp[i - 1], dp[i - 2] + nums[i]));
	}
	return dp.back();
}

//法2
int rob2(vector<int>& nums) {
	int robEven = 0, robOdd = 0, n = nums.size();
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			robEven = max(robEven + nums[i], robOdd);
		}
		else {
			robOdd = max(robEven + nums[i], robEven);
		}
	}
	return max(robOdd, robEven);
}

int main() {
	int temp;
	vector<int> test;
	while (cin >> temp) {
		test.push_back(temp);
	}
	cout << rob1(test) << endl;
	cout << rob2(test) << endl;
	system("pause");
	return 0;
}