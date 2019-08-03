/*leetcode 454. 4Sum II
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] 
is zero.To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 
to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:
Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]
Output:
2
Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

用两个哈希来做,分别记录AB和CB的两两之和出现次数，然后遍历其中一个哈希表，并在另一个哈希表中找和的相反数出现的次数
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
	int res = 0;
	unordered_map<int, int> m1, m2;
	int n = A.size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			++m1[A[i] + B[j]];
			++m2[C[i] + D[j]];
		}
	}
	for (auto a : m1) {
		res += a.second * m2[-a.first];
	}
	return res;
}

int main() {
	int temp1, temp2, temp3, temp4;
	vector<int> test1, test2, test3, test4;
	while (cin >> temp1) {
		test1.push_back(temp1);
	}
	while (cin >> temp2) {
		test2.push_back(temp2);
	}
	while (cin >> temp3) {
		test3.push_back(temp3);
	}
	while (cin >> temp4) {
		test4.push_back(temp4);
	}
	cout << fourSumCount(test1, test2, test3, test4) << endl;
	system("pause");
	return 0;
}