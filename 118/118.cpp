/*leetcode 118. Pascal's Triangle
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

Example:
Input: 5
Output:
[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]


*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
	vector<vector<int> > res(numRows, vector<int>());
	for (int i = 0; i < numRows; ++i) {
		res[i].resize(i + 1, i);
		for (int j = 1; j < i; ++j) {
			res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
		}
	}
	return res;
}

int main() {
	int test;
	vector<vector<int> > res;
	cin >> test;
	res = generate(test);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[0].size(); ++j) {
			cout << res[i][j] << endl;
		}
	}
	system("pause");
	return 0;
}