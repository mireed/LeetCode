/*leetcode 55. Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.Each element in the array represents your 
maximum jump length at that position.Determine if you are able to reach the last index.

Example 1:
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:
Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
jump length is 0, which makes it impossible to reach the last index.

贪婪算法Greedy Algorithm，维护一个变量reach，表示最远能到达的位置，初始化为0。遍历数组中每一个数字，如果当前坐标大于reach或者reach已经抵达最后一个位
置则跳出循环，否则就更新reach的值为其和i + nums[i]中的较大值，其中i + nums[i]表示当前位置能到达的最大位置
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canJump(vector<int>& nums) {
	int reach = 0;
	for (int i = 0; i < nums.size(); ++i) {
		if (i > reach || reach >= nums.size() - 1) {
			break;
		}
		reach = max(reach, i + nums[i]);
	}
	return reach >= nums.size() - 1;
}

int main() {
	vector<int> test;
	int temp;
	while (cin >> temp) {
		test.push_back(temp);
	}
	cout << canJump(test) << endl;
	system("pause");
	return 0;
}