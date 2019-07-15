/*leetcode 283. Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements

Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

���滻��in-place��������Ҫ������ָ�룬һ����ͣ�����ɨ���ҵ�����λ�ã�Ȼ���ǰ���Ǹ�ָ�뽻��λ�ü���
*/

#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums){
	for (int i = 0, j = 0; i < nums.size(); ++i) {
		if (nums[i]) {
			swap(nums[i], nums[j++]);
		}
	}
}

int main() {
	vector<int> test;
	int temp;
	cout << "������ԭ���飺" << endl;
	while (cin >> temp) {
		test.push_back(temp);
	}
	moveZeroes(test);
	for (int i = 0; i < test.size(); ++i) {
		cout << test[i] << " " << endl;
	}
	system("pause");
	return 0;
}