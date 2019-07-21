/*leetcode 268. Missing Number
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:
Input: [3,0,1]
Output: 2
Example 2:
Input: [9,6,4,2,3,5,7,0,1]
Output: 8

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

法1：位操作，将给的数组与完整的不缺数的数组异或就得到了结果
法2：0到n等差数列求和后减去给定数组的和
法3：若没有要求线性时间复杂度和常数级空间复杂度，可以先排序再用二分查找
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//法1
int missingNumber1(vector<int>& nums) {
	if (nums.empty()) {
		return 0;
	}
	int res = 0;
	for (int i = 0; i < nums.size(); ++i) {
		res ^= (i + 1) ^ nums[i];
	}
	return res;
}

//法2
int missingNumber2(vector<int>& nums) {
	if (nums.empty()) {
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < nums.size(); ++i) {
		sum += nums[i];
	}
	int n = nums.size();
	int res = n * (n + 1) / 2 - sum;
	return res;
}

//法3
int missingNumber3(vector<int>& nums) {
	if (nums.empty()) {
		return 0;
	}
	sort(nums.begin(), nums.end());
	int left = 0, right = nums.size();
	while (left < right) {
		int mid = (left + right) / 2;
		if (nums[mid] <= mid) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return right;
}

int main() {
	int res1, res2, res3, temp;
	vector<int> test;
	while (cin >> temp) {
		test.push_back(temp);
	}
	res1 = missingNumber1(test);
	res2 = missingNumber2(test);
	res3 = missingNumber3(test);
	cout << res1 << res2 << res3 << endl;
	system("pause");
	return 0;
}