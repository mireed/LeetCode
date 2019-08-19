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

��1���ø�set��nums1���Ž�ȥ��Ȼ�����nums2��Ԫ�أ������set�д��ڣ�˵���ǽ����Ĳ��֣���������set�У�����ٰѽ��תΪvector����ʽ
��2:ʹ������ָ���������ȸ�������������Ȼ��������ָ��ֱ�ָ����������Ŀ�ͷ��Ȼ��Ƚ���������Ĵ�С����С�����ֵ�ָ������ƣ��������
    ָ��ָ��������ȣ���ô�����res�Ƿ�Ϊ�գ����Ϊ�ջ��������һ�����ֺ͵�ǰ���ֲ��ȵĻ����������ּ�����res��
��3��ʹ�ö��ֲ��ҷ�������˼·�ǽ�һ����������Ȼ�������һ�����飬�ѱ�������ÿ������������õ��������ö��ֲ��ҷ�������������ҵ����
    ����set�У����������õ���set��ȥ�ظ������ԣ�������ǽ�setתΪvector����
��4:ʹ��STL��set_intersection�������ҳ���ͬԪ��
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
