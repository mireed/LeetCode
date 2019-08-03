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

��1���ǵݹ飬����һλһλ�����ϵ��ӣ����������Ŀ�и������� [1,2,3] ��˵���ʼ�ǿռ�����ô����Ҫ����1�����ڿռ��ϼ�1��Ϊ [1]������������
     �Լ� [] �� [1]������������2����֮ǰ���Ӽ������ϣ�ÿ�����Ӹ�2�����Էֱ�õ� [2]��[1, 2]����ô�������е��Ӽ���Ϊ [], [1], [2], [1, 2]��
	 ͬ����3������ɵ� [3], [1, 3], [2, 3], [1, 2, 3], �ټ���֮ǰ���Ӽ��������е��Ӽ�����
��2���ݹ�,DFS����.����ÿһ������ֻ������״̬��Ҫô���ڣ�Ҫô�����ڣ���ô�ڹ����Ӽ�ʱ����ѡ��Ͳ�ѡ��������������Կ��Թ���һ�ö�������������
    ��ʾѡ��ò㴦��Ľڵ㣬��������ʾ��ѡ�����յ�Ҷ�ڵ���������Ӽ���
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

//��1
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

//��2
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
