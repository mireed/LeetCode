/*leetcode 217. Contains Duplicate
Given an array of integers, find if the array contains any duplicates.Your function should return true if any value appears at 
least twice in the array, and it should return false if every element is distinct.

Example 1:
Input: [1,2,3,1]
Output: true
Example 2:
Input: [1,2,3,4]
Output: false
Example 3:
Input: [1,1,1,3,3,4,3,2,4,2]
Output: true

哈希表，或者先排序再判断相邻数字是否相等
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool containsDuplicate1(vector<int>& nums) {
	unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); ++i) {
		if (m.find(nums[i]) != m.end()) {//end返回指向容器末尾位置的迭代器,find通过给定主键查找元素,没找到：返回unordered_map::end,此处说明找到了返回true
			return true;
		}
		++m[nums[i]];
	}
	return false;
}

bool containsDuplicate2(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	for (int i = 1; i < nums.size(); ++i) {
		if (nums[i] == nums[i - 1]) {
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
	cout << containsDuplicate1(test) << endl;
	cout << containsDuplicate2(test) << endl;
	system("pause");
	return 0;
}