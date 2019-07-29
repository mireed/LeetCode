/*leetcode 189. Rotate Array
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:
Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

看做从数组的末尾取k个数组放入数组的开头
*/

#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k) {
	if (nums.empty() || (k %= nums.size() == 0)) {
		return;
	}
	for (int i = 0; i < nums.size() - k; ++i) {
		nums.push_back(nums[0]);
		nums.erase(nums.begin());
	}
}

int main() {
	int test1, temp;
	vector<int> test2;
	cin >> test1;
	while (cin >> temp) {
		test2.push_back(temp);
	}
	rotate(test2, test1);
	for (int i = 0; i < test2.size(); ++i) {
		cout << test2[i] << endl;
	}
	system("pause");
	return 0;
}