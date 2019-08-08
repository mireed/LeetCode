/*leetcode 48. Rotate Image
You are given an n x n 2D matrix representing an image.Rotate the image by 90 degrees (clockwise).

Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D 
matrix and do the rotation.

Example 1:
Given input matrix =
[
[1,2,3],
[4,5,6],
[7,8,9]
],
rotate the input matrix in-place such that it becomes:
[
[7,4,1],
[8,5,2],
[9,6,3]
]
Example 2:
Given input matrix =
[
[ 5, 1, 9,11],
[ 2, 4, 8,10],
[13, 3, 6, 7],
[15,14,12,16]
],
rotate the input matrix in-place such that it becomes:
[
[15,13, 2, 5],
[14, 3, 4, 1],
[12, 6, 8, 9],
[16, 7,10,11]
]

顺时针旋转90度可以看做先对矩阵进行转置然后再将每行的数字反转
*/

#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; j++) {
			swap(matrix[i][j], matrix[j][i]);
		}
		reverse(matrix[i].begin(), matrix[i].end());
	}
}

int main() {
	int a;
	vector<int> temp;
	vector<vector<int> > test;
	bool flag = true;
	while (flag) {
		do {
			cin >> a;
			if (!cin) {
				flag = false;
				break;
			}
			temp.push_back(a);
		} while (cin.get() != '\n');
		if (flag) {
			test.push_back(temp);
			temp.clear();
		}
	}
	rotate(test);
	for (int i = 0; i < test.size(); ++i) {
		for (int j = 0; j < test[0].size(); ++j) {
			cout << test[i][j] << endl;
		}
	}
	system("pause");
	return 0;
}