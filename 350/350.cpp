/*leetcode 350. Intersection of Two Arrays II
Given two arrays, write a function to compute their intersection.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory 
at once?

法1：建立哈希映射
法2：先排序再利用双指针
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

//法1
vector<int> intersect1(vector<int>& nums1, vector<int>& nums2) {
	int length1 = sizeof(nums1) / sizeof(int);
	int length2 = sizeof(nums2) / sizeof(int);
	vector<int> s, l, res;
	unordered_map<int, int> m;
	if (length1 < length2) {
		s = nums1;
		l = nums2;
	}
	else {
		s = nums2;
		l = nums1;
	}
	for (auto a : s) {
		++m[a];
	}
	for (auto a : l) {
		if (m[a]-- > 0) {
			res.push_back(a);
		}
	}
	return res;
}

//法2
vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	vector<int> res;
	int i = 0, j = 0;
	while (i < nums1.size() && j < nums2.size()) {
		if (nums1[i] == nums2[j]) {
			res.push_back(nums1[i]);
			i++, j++;
		}
		else if (nums1[i] < nums2[j]) {
			i++;
		}
		else {
			j++;
		}
	}
	return res;
}

int main() {
	int temp1,temp2;
	vector<int> test1, test2, res1, res2;
	cout << "请输入第一个数组：" << endl;
	while (cin >> temp1) {
		test1.push_back(temp1);
	}
	cout << "请输入第二个数组：" << endl;
	while (cin >> temp2) {
		test2.push_back(temp2);
	}
	res1 = intersect1(test1, test2);
	res2 = intersect2(test1, test2);
	for (int i = 0; i < res1.size(); ++i) {
		cout << res1[i] << endl;
	}
	for (int i = 0; i < res2.size(); ++i) {
		cout << res2[i] << endl;
	}
	system("pause");
	return 0;
}