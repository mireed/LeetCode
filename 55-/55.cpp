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

̰���㷨Greedy Algorithm��ά��һ������reach����ʾ��Զ�ܵ����λ�ã���ʼ��Ϊ0������������ÿһ�����֣������ǰ�������reach����reach�Ѿ��ִ����һ��λ
��������ѭ��������͸���reach��ֵΪ���i + nums[i]�еĽϴ�ֵ������i + nums[i]��ʾ��ǰλ���ܵ�������λ��
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