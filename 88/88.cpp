/*leetcode 88. Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

Example:
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
Output: [1,2,2,3,5,6]


*/

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i = m - 1, j = n - 1, k = m + n - 1;
	while (i >= 0 && j >= 0) {
		if (nums1[i] > nums2[j]) {
			nums1[k] = nums1[i];
			i--;
			k--;
		}
		else {
			nums1[k] = nums2[j];
			j--;
			k--;
		}
	}
	while (j >= 0) {
		nums1[k] = nums2[j];
		j--;
		k--;
	}
}

int main() {
	vector<int> test1, test2;
	int temp1, temp2;
	while (cin >> temp1) {
		test1.push_back(temp1);
	}
	while (cin >> temp2) {
		test2.push_back(temp2);
	}
	int m = test1.size(), n = test2.size();
	merge(test1, m, test2, n);
	for (int i = 0; i < test1.size(); ++i) {
		cout << test1[i] << endl;
	}
	system("pause");
	return 0;
}