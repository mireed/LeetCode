/*leetcdoe 39. Combination Sum
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in 
candidates where the candidate numbers sums to target.The same repeated number may be chosen from candidates unlimited number of 
times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
[7],
[2,2,3]
]
Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
[2,2,2,2],
[2,3,3],
[3,5]
]

»ØËÝ·¨£¬DFSµÝ¹é
*/

#include <iostream>
#include <vector>

using namespace std;

void helpDFS(vector<int>& candidates, vector<vector<int>>& res, int target, vector<int>& out, int start) {
	if (target < 0) {
		return;
	}
	if (target == 0) {
		res.push_back(out);
		return;
	}
	for (int i = start; i < candidates.size(); ++i) {
		out.push_back(candidates[i]);
		helpDFS(candidates, res, target - candidates[i], out, i);
		out.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> res;
	vector<int> out;
	helpDFS(candidates, res, target, out, 0);
	return res;
}

int main() {
	vector<vector<int>> result;
	vector<int> test1;
	int test2, temp;
	while (cin >> temp) {
		test1.push_back(temp);
	}
	cin >> test2;
	result = combinationSum(test1, test2);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[0].size(); ++j) {
			cout << result[i][j] << endl;
		}
	}
	system("pause");
	return 0;
}