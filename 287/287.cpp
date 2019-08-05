/*leetcode 287. Find the Duplicate Number
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate 
number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:
Input: [1,3,4,2,2]
Output: 2
Example 2:
Input: [3,1,3,4,2]
Output: 3

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

题目要求不能用额外的空间也不能给改变原数组，所以无法用哈希表，再要求时间复杂度小于O（N2），所以不能暴力搜索，有以下方法：
法1：二分搜索，在区间[1,n]搜索，首先求出中点mid，然后遍历整个数组找出小于等于mid的数的个数，若个数小于等于mid，说明重复值在【mid+1，n】
之间，否则在另一边
*/

#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(vector<int>& nums) {
	int left = 0, right = nums.size();
	while (left < right) {
		int mid = left + (right - left) / 2;
		int count = 0;
		for (auto num : nums) {
			if (num <= mid) {
				++count;
			}
		}
		if (count <= mid) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return right;
}

int main() {
	vector<int> test;
	int temp;
	while (cin >> temp) {
		test.push_back(temp);
	}
	cout << findDuplicate(test) << endl;
	system("pause");
	return 0;
}