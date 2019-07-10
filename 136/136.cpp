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

hashset�����������䳣�����Ĳ����ٶȡ����������е�ÿ�����֣�����ǰ�����Ѿ��� HashSet ���ˣ��� HashSet �еĸ������Ƴ�������ͼ��� HashSet��

*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//hashset���������ң��������˶���ռ�
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

//�����ö���ռ䣬λ�����߼����������
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
	cout << "���������飺" << endl;
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