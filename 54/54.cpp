/*leetcode 54. Spiral Matrix
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

  Example 1:
Input:
[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

  Example 2:
Input:
[
[1, 2, 3, 4],
[5, 6, 7, 8],
[9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
  
  初始化的时候，上边top就是0，下边bottom就是m-1，左边left是0，右边right是n-1。
然后我们进行while循环，先遍历上边，将所有元素加入结果res，然后上边下移一位，如果此时上边大于下边，
说明此时已经遍历完成了，直接break。同理对于下边，左边，右边，依次进行相对应的操作
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> res;
	if (matrix.empty() || matrix[0].empty()) {
		return{};
	}
	int m = matrix.size(), n = matrix[0].size();
	int top = 0, bottom = m - 1, left = 0, right = n - 1;
	while (true) {
		for (int i = left; i <= right; ++i) {
			res.push_back(matrix[top][i]);
		}
		if (++top > bottom) {
			break;
		}
		for (int i = top; i <= bottom; ++i) {
			res.push_back(matrix[i][right]);
		}
		if (--right < left) {
			break;
		}
		for (int i = right; i >= left; --i) {
			res.push_back(matrix[bottom][i]);
		}
		if (--bottom < top) {
			break;
		}
		for (int i = bottom; i >= top; --i) {
			res.push_back(matrix[i][left]);
		}
		if (++left > right) {
			break;
		}
	}
	return res;
}

int main() {
	vector<vector<int>> test;
	vector<int> temp;
	int t;
	bool flag = true;
	cout << "请输入二维数组：" << endl;
	while (flag) {
		do {
			cin >> t;
			if (!cin) {
				flag = false;
				break;
			}
			temp.push_back(t);
		} while (cin.get() != '\n');
		if (flag) {
			test.push_back(temp);
			temp.clear();
		}
	}
	vector<int> result;
	result = spiralOrder(test);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	system("pause");
	return 0;
}