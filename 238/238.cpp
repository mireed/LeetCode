/*leetcode 238. Product of Array Except Self
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the
elements of nums except nums[i].

Example:
Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

ʱ�临�Ӷ� O(n)�����Ҳ��ó���
����ĳһ�����֣����֪����ǰ���������ֵĳ˻���ͬʱҲ֪���������е����˻�����ô������˾���Ҫ�Ľ��������ֻҪ�ֱ𴴽������������鼴�ɣ�
�ֱ�������������������Ϳ��Էֱ𴴽����˻��ۻ�����
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