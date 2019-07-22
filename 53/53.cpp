/*leetcode 53. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return 
its sum.

Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

//法1：O(n):遍历，比较当前最大值与当前最大值和当前值和的大小
//法2：O（nlogn）:分治法:类似于二分搜索法，我们需要把数组一分为二，分别找出左边和右边的最大子数组之和，然后还要从中间开始向左右分别扫描，求出
       的最大值分别和左右两边得出的最大值相比较取最大的那一个
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//法1
int maxSubArray1(vector<int>& nums) {
	int res = INT_MIN, cur = 0;
	for (int i = 0; i < nums.size(); ++i) {
		cur = max(cur, cur + nums[i]);
		res = max(res, cur);
	}
	return res;
}

//法2
int maxSubArray2(vector<int>& nums) {
	if (nums.size() == 0) {
		return 0;
	}
	return maxSubArray2core(nums, 0, nums.size() - 1);
}
int maxSubArray2core(vector<int>& nums, int left, int right) {
	if (left >= right) {
		return nums[left];
	}
	int mid = left + (right - left) / 2;
	int lmax = maxSubArray2core(nums, left, mid - 1);
	int rmax = maxSubArray2core(nums, mid + 1, right);
	int mmax = nums[mid];
	int temp = mmax;
	for (int i = mid - 1; i >= 0; --i) {
		temp += nums[i];
		mmax = max(mmax, temp);
	}
	temp = mmax;
	for (int i = mid + 1; i <= right; ++i) {
		temp += nums[i];
		mmax = max(mmax, temp);
	}
	return max(mmax, max(lmax, rmax));
}

int main() {
	int temp;
	vector<int> test;
	while (cin >> temp) {
		test.push_back(temp);
	}
	cout << maxSubArray1(test) << endl;
	cout << maxSubArray2(test) << endl;
	system("pause");
	return 0;
}