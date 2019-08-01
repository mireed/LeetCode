/*leetcode 238. Product of Array Except Self
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the
elements of nums except nums[i].

Example:
Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

时间复杂度 O(n)，并且不用除法
对于某一个数字，如果知道其前面所有数字的乘积，同时也知道后面所有的数乘积，那么二者相乘就是要的结果，所以只要分别创建出这两个数组即可，
分别从数组的两个方向遍历就可以分别创建出乘积累积数组
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
	int n = nums.size();
	vector<int> v1(n, 1), v2(n, 1), res(n);
	for (int i = 0; i < n - 1; ++i) {
		v1[i + 1] = v1[i] * nums[i];
	}
	for (int i = n - 1; i > 1; --i) {
		v2[i - 1] = v2[i] * nums[i];
	}
	for (int i = 0; i < n; ++i) {
		res[i] = v1[i] * v2[i];
	}
	return res;
}

int main() {
	vector<int> test, result;
	int temp;
	while (cin >> temp) {
		test.push_back(temp);
	}
	result = productExceptSelf(test);
	for (int i = 0; i < test.size(); ++i) {
		cout << result[i] << endl;
	}
	system("pause");
	return 0;
}