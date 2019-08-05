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
You may assume k is always valid, 1 �� k �� n2.

�������ѣ��������齫Ԫ�ؼ�����У�Ȼ����ܵ�ǰԪ�ظ����Ƿ����k���ǵĻ��ͽ���Ԫ��ȥ����ѭ��������ȥ����Ԫ�ؼ���

���߶������������ö��ֲ����е�upper_bound����
    1  ����lower_bound() 
    ����lower_bound()��first��last�е�ǰ�պ�������ж��ֲ��ң����ش��ڻ����val�ĵ�һ��Ԫ��λ�á��������Ԫ�ض�С��val���򷵻�last��λ��.
    ע�⣺�������Ԫ�ض�С��val���򷵻�last��λ�ã���last��λ����Խ��ģ���
    2 ����upper_bound()
    ����upper_bound()���ص���ǰ�պ�������ҵĹؼ��ֵ��Ͻ磬���ش���val�ĵ�һ��Ԫ��λ��
    ���ز���Ԫ�ص����һ���ɰ���λ�ã�Ҳ���ǡ�Ԫ��ֵ>����ֵ���ĵ�һ��Ԫ�ص�λ�á�ͬ�������val����������ȫ��Ԫ�أ����ص���last��
	(ע�⣺�����±�Խ��)
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