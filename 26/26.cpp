/*leetcode 26. Remove Duplicates from Sorted Array
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Given nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the returned length.
Example 2:
Given nums = [0,0,1,1,1,2,2,3,3,4],
Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
It doesn't matter what values are set beyond the returned length.

¿‡À∆øÏ¬˝÷∏’Î
*/

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates1(vector<int>& nums) {
	if (nums.empty()) {
		return 0;
	}
	int p1 = 0, p2 = 0, n = nums.size();
	while (p2 < n) {
		if (nums[p1] == nums[p2]) {
			++p2;
		}
		else {
			nums[++p1] = nums[p2++];
		}
	}
	return p1 + 1;
}

int removeDuplicates2(vector<int>& nums) {
	if (nums.empty()) {
		return 0;
	}
	int j = 0;
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] != nums[j]) {
			nums[++j] = nums[i];
		}
	}
	return j + 1;
}

int main() {
	int temp;
	vector<int> test;
	while (cin >> temp) {
		test.push_back(temp);
	}
	cout << removeDuplicates1(test) << endl;
	cout << removeDuplicates2(test) << endl;
	system("pause");
	return 0;
}