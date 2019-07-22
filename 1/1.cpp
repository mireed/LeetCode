/*leetcode 1. Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

哈希表，建立索引和值的映射
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); ++i) {
		if (m[target - nums[i]]) {
			return{ i, target - nums[i] };
		}
		m[nums[i]] = i;
	}
	return{};
}

int main() {
	int test2, temp;
	vector<int> test1, res;
	cin >> test2;
	while (cin >> temp) {
		test1.push_back(temp);
	}
	res = twoSum(test1, test2);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}
	system("pause");
	return 0;
}