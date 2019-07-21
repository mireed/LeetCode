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

��1��λ�����������������������Ĳ�ȱ�����������͵õ��˽��
��2��0��n�Ȳ�������ͺ��ȥ��������ĺ�
��3����û��Ҫ������ʱ�临�ӶȺͳ������ռ临�Ӷȣ��������������ö��ֲ���
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//��1
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

//��2
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

//��3
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