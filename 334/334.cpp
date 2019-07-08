/*leetcode 334. Increasing Triplet Subsequence
  Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
Formally the function should:
Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 �� i < j < k �� n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example 1:
Input: [1,2,3,4,5]
Output: true
Example 2:
Input: [5,4,3,2,1]
Output: false

  ʹ������ָ��m1��m2����ʼ��Ϊ�������ֵ�����Ǳ������飬���m1���ڵ��ڵ�ǰ���֣��򽫵�ǰ���ָ���m1��
���m1С�ڵ�ǰ������m2���ڵ��ڵ�ǰ���֣���ô����ǰ���ָ���m2��һ��m2�������ˣ�˵��һ������һ����С��m2��
��ô���Ǿͳɹ��������һ������Ϊ2�ĵ��������У���������һ����������m2�������������ֱ�ӷ���ture���������������m1С������
����Ҫ����m1���п��ܵĻ�ҲҪ����m2Ϊ��С��ֵ���Ͼ�m2��ֵԽС������ɳ���Ϊ3�ĵ������еĿ�����Խ��
*/

#include <iostream>
#include <vector>

using namespace std;

bool increasingTriplet(vector<int>& nums) {
	int m1 = INT_MAX;
	int m2 = INT_MAX;
	for (int i = 0; i < nums.size(); i++) {
		if (m1 >= nums[i]) {
			m1 = nums[i];
		}
		else if (m2 >= nums[i]) {
			m2 = nums[i];
		}
		else {
			return true;
		}
	}
	return false;
}

int main() {
	vector<int> test;
	int temp;
	while (cin >> temp) {
		test.push_back(temp);
	}
	bool flag = increasingTriplet(test);
	cout << flag << " ";
	cout << endl;
	system("pause");
	return 0;
}
