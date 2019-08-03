/*leetcode 78. Subsets
Given a set of distinct integers, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.

Example:
Input: nums = [1,2,3]
Output:
[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]

法1：非递归，可以一位一位的往上叠加，比如对于题目中给的例子 [1,2,3] 来说，最开始是空集，那么现在要处理1，就在空集上加1，为 [1]，现在有两个
     自己 [] 和 [1]，下面来处理2，在之前的子集基础上，每个都加个2，可以分别得到 [2]，[1, 2]，那么现在所有的子集合为 [], [1], [2], [1, 2]，
	 同理处理3的情况可得 [3], [1, 3], [2, 3], [1, 2, 3], 再加上之前的子集就是所有的子集合了
法2：递归,DFS搜索.集合每一个数字只有两种状态，要么存在，要么不存在，那么在构造子集时就有选择和不选择两种情况，所以可以构造一棵二叉树，左子树
    表示选择该层处理的节点，右子树表示不选择，最终的叶节点就是所有子集合
	      []
	  /        \
	/            \
	/              \
	[1]                []
	/       \           /    \
	/         \         /      \
	[1 2]       [1]       [2]     []
	/     \     /   \     /   \    / \
	[1 2 3] [1 2] [1 3] [1] [2 3] [2] [3] []
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//法1
vector<vector<int>> subsets1(vector<int>& nums) {
	vector<vector<int> > res(1);
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); ++i) {
		int n = res.size();
		for (int j = 0; j < n; j++) {
			res.push_back(res[j]);
			res.back().push_back(nums[i]);
		}
	}
	return res;
}

//法2
class Solution {
public:
	vector<vector<int>> subsets2(vector<int>& nums) {
		vector<vector<int> > res;
		vector<int> out;
		sort(nums.begin(), nums.end());
		subsetDFS(nums, 0, res, out);
		return res;
	}
	void subsetDFS(vector<int>& nums, int pos, vector<vector<int> >& res, vector<int>& out) {
		res.push_back(out);
		for (int i = pos; i < nums.size(); ++i) {
			out.push_back(nums[i]);
			subsetDFS(nums, i + 1, res, out);
			out.pop_back();
		}
	}
};

int main() {
	int temp;
	vector<int> test;
	vector<vector<int> > result1, result2;
	while (cin >> temp) {
		test.push_back(temp);
	}
	result1 = subsets1(test);
	Solution s;
	result2 = s.subsets2(test);
	for (int i = 0; i < result1.size(); ++i) {
		for (int j = 0; j < result1[0].size(); ++j) {
			cout << result1[i][j] << endl;
		}
	}
	for (int i = 0; i < result2.size(); ++i) {
		for (int j = 0; j < result2[0].size(); ++j) {
			cout << result2[i][j] << endl;
		}
	}
	system("pause");
	return 0;
}
