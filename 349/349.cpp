/*leetcode 349. Intersection of Two Arrays
Given two arrays, write a function to compute their intersection.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:
Each element in the result must be unique.
The result can be in any order.

法1：用个set把nums1都放进去，然后遍历nums2的元素，如果在set中存在，说明是交集的部分，加入结果的set中，最后再把结果转为vector的形式
法2:使用两个指针来做，先给两个数组排序，然后用两个指针分别指向两个数组的开头，然后比较两个数组的大小，把小的数字的指针向后移，如果两个
    指针指的数字相等，那么看结果res是否为空，如果为空或者是最后一个数字和当前数字不等的话，将该数字加入结果res中
法3：使用二分查找法来做，思路是将一个数组排序，然后遍历另一个数组，把遍历到的每个数字在排序好的数组中用二分查找法搜索，如果能找到则放
    入结果set中，这里我们用到了set的去重复的特性，最后我们将set转为vector即可
法4:使用STL的set_intersection函数来找出共同元素
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution1 {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> s(nums1.begin(), nums1.end()), res;
		for (auto a : nums2) {
			if (s.count(a)) {
				res.insert(a);
			}
		}
		return vector<int>(res.begin(), res.end());
	}
};

class Solution2 {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int p1 = 0, p2 = 0;
		vector<int> res;
		while (p1 < nums1.size() && p2 < nums2.size()) {
			if (nums1[p1] < nums2[p2]) {
				++p1;
			}
			else if (nums1[p1] > nums2[p2]) {
				++p2;
			}
			else {
				if (res.empty() || res.back() != nums1[p1]) {
					res.push_back(nums1[p1]);
				}
				++p1;
				++p2;
			}
		}
		return res;
	}
};

class Solution3 {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		set<int> res;
		for (auto a : nums2) {
			if (helper(nums1, a)) {
				res.insert(a);
			}
		}
		return vector<int>(res.begin(), res.end());
	}
	bool helper(vector<int>& nums, int target) {
		int left = 0, right = nums.size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				return true;
			}
			else if (nums[mid] < target) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return false;
	}
};

class Solution4 {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end()), res;
		set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
		return vector<int>(res.begin(), res.end());
	}
};
