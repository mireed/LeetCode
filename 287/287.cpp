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

��ĿҪ�����ö���Ŀռ�Ҳ���ܸ��ı�ԭ���飬�����޷��ù�ϣ����Ҫ��ʱ�临�Ӷ�С��O��N2�������Բ��ܱ��������������·�����
��1������������������[1,n]��������������е�mid��Ȼ��������������ҳ�С�ڵ���mid�����ĸ�����������С�ڵ���mid��˵���ظ�ֵ�ڡ�mid+1��n��
֮�䣬��������һ��
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