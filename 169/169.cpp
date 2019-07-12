/*leetcode 169. Majority Element
  Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:
Input: [3,2,3]
Output: 3
Example 2:
Input: [2,2,1,1,1,2,2]
Output: 2

法1：哈希表
法2：摩尔投票法
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//法1
int majorityElement1(vector<int>& nums) {
	unordered_set<int> s;
	for (int i = 0; i < nums.size(); ++i) {
		if (!s.count(nums[i])) {
			s.insert(nums[i]);
		}
		else {
			s.erase(nums[i]);
		}
	}
	return *s.begin();
}

//法2
int majorityElement2(vector<int>& nums) {
	int res = 0, cnt = 0;
	for (int num : nums) {
		if (cnt == 0) {
			res = num;
			++cnt;
		}
		else {
			if (num == res) {
				++cnt;
			}
			else {
				--cnt;
			}
		}
	}
	return res;
}

int main() {
	vector<int> test;
	int result, temp;
	while (cin >> temp) {
		test.push_back(temp);
	}
	result = majorityElement2(test);
	cout << result << endl;
	system("pause");
	return 0;
}
