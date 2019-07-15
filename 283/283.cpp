/*leetcode 283. Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements

Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

用替换法in-place来做，需要用两个指针，一个不停的向后扫，找到非零位置，然后和前面那个指针交换位置即可
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
	cout << "请输入原数组：" << endl;
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