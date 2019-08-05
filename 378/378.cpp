/*leetcode 378. Kth Smallest Element in a Sorted Matrix
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:
matrix = [
[ 1,  5,  9],
[10, 11, 13],
[12, 13, 15]
],
k = 8,
return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.

利用最大堆，遍历数组将元素加入堆中，然后可能当前元素个数是否大于k，是的话就将首元素去掉，循环结束后去掉首元素即可

或者二分搜索，利用二分查找中的upper_bound函数
    1  函数lower_bound() 
    函数lower_bound()在first和last中的前闭后开区间进行二分查找，返回大于或等于val的第一个元素位置。如果所有元素都小于val，则返回last的位置.
    注意：如果所有元素都小于val，则返回last的位置，且last的位置是越界的！！
    2 函数upper_bound()
    函数upper_bound()返回的在前闭后开区间查找的关键字的上界，返回大于val的第一个元素位置
    返回查找元素的最后一个可安插位置，也就是“元素值>查找值”的第一个元素的位置。同样，如果val大于数组中全部元素，返回的是last。
	(注意：数组下标越界)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthSmallest1(vector<vector<int>>& matrix, int k) {
	priority_queue<int> q;
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			q.push(matrix[i][j]);
			if (q.size() > k) {
				q.pop();
			}
		}
	}
	return q.top();
}

int kthSmallest2(vector<vector<int>>& matrix, int k) {
	int left = matrix[0][0], right = matrix.back().back();
	while (left < right) {
		int mid = left + (right - left) / 2;
		int count = 0;
		for (int i = 0; i < matrix.size(); ++i) {
			count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
		}
		if (count < k) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return left;
}

int main() {
	vector<int> temp;
	vector<vector<int>> test;
	int t1, t2;
	bool flag = true;
	while (flag) {
		do {
			cin >> t1;
			if (!cin) {
				flag = false;
				break;
			}
			temp.push_back(t1);
		} while (cin.get() != '\n');
		if (flag) {
			test.push_back(temp);
			temp.clear();
		}
	}
	cin >> t2;
	cout << kthSmallest1(test, t2) << endl;
	cout << kthSmallest2(test, t2) << endl;
	system("pause");
	return 0;
}