/*leetcode 73. Set Matrix Zeroes
  Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:
Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:
Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

Follow up:
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

	空间复杂度为O(mn)的解法，直接新建一个和matrix等大小的矩阵，然后一行一行的扫，只要有0，就将新建的矩阵的对应行全赋0，
行扫完再扫列，然后把更新完的矩阵赋给matrix即可，这个算法的空间复杂度太高。O(m+n)的方法是，用一个长度为m的一维数组记录各
行中是否有0，用一个长度为n的一维数组记录各列中是否有0，最后直接更新matrix数组即可。O(1)的空间，就用原数组的第一行第一列
来记录各行各列是否有0.
- 先扫描第一行第一列，如果有0，则将各自的flag设置为true
- 然后扫描除去第一行第一列的整个数组，如果有0，则将对应的第一行和第一列的数字赋0
- 再次遍历除去第一行第一列的整个数组，如果对应的第一行和第一列的数字有一个为0，则将当前值赋0
- 最后根据第一行第一列的flag来更新第一行第一列
*/

#include <iostream>
#include <vector>

using namespace std;


	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return;
		}
		int m = matrix.size();
		int n = matrix[0].size();
		bool colflag = false;
		bool rowflag = false;
		for (int i = 0; i < m; i++) {
			if (matrix[i][0] == 0) {
				colflag = true;
			}
		}
		for (int j = 0; j < n; j++) {
			if (matrix[0][j] == 0) {
				rowflag = true;
			}
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
			}
		}
		if (colflag) {
			for (int i = 0; i < m; i++) {
				matrix[i][0] = 0;
			}
		}
		if (rowflag) {
			for (int j = 0; j < n; j++) {
				matrix[0][j] = 0;
			}
		}
	}

	int main() {
		vector <vector<int> > test;
		vector <int> v;
		int m, n, temp;
		cout << "请输入行列数：" << endl;
		cin >> m >> n;
		test.clear();
		cout << "请输入二维数组：" << endl;
		for (int i = 0; i < m; i++) {
			v.clear();
			for (int j = 0; j < n; j++) {
				cin >> temp;
				v.push_back(temp);
			}
			test.push_back(v);
		}
		setZeroes(test);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << test[i][j] << " ";
			}
			cout << endl;
		}
		system("pause");
		return 0;
	}
