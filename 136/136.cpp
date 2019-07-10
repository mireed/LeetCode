/*leetcode 136. Single Number
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:
Input: [2,2,1]
Output: 1
Example 2:
Input: [4,1,2,1,2]
Output: 4

hashset来做，利用其常数级的查找速度。遍历数组中的每个数字，若当前数字已经在 HashSet 中了，则将 HashSet 中的该数字移除，否则就加入 HashSet。

*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//hashset常数级查找，但利用了额外空间
class Solution1 {
public:
	int singleNumber1(vector<int>& nums) {
		unordered_set<int> s;
		for (int i = 0; i < nums.size(); ++i) {
			if (s.count(nums[i])) {
				s.erase(nums[i]);
			}
			else {
				s.insert(nums[i]);
			}
		}
		return *s.begin();
	}
};

//不利用额外空间，位操作逻辑异或来处理
class Solution2 {
public:
	int singleNumber2(vector<int>& nums) {
		int res = 0;
		for (int it : nums) {
			res ^= it;
		}
		return res;
	}
};

int main() {
	int result1, result2, temp;
	vector<int> test;
	cout << "请输入数组：" << endl;
	while (cin >> temp) {
		test.push_back(temp);
	}
	Solution1 s1;
	Solution2 s2;
	result1 = s1.singleNumber1(test);
	result2 = s2.singleNumber2(test);
	cout << result1  << result2 << endl;
	system("pause");
	return 0;
}