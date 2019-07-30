/*leetcode 46. Permutations
Given a collection of distinct integers, return all possible permutations.

Example:
Input: [1,2,3]
Output:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]

��1��DFS�ݹ�
��2��STL����ȫ���к���
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//��1��DFS�ݹ�
class Solution1 {
public:
	vector<vector<int>> permute(vector<int>& num) {
		vector<int> out;
		vector<int> visited(num.size(), 0);
		vector<vector<int> > res;
		permuteDFS(num, 0, out, visited, res);
	}
	void permuteDFS(vector<int>& num, int level, vector<int>& out, vector<int>& visited, vector<vector<int>>& res) {
		/*level ��¼��ǰ�Ѿ�ƴ���ĸ�����һ����ﵽ��nums����ĳ��ȣ�˵����ʱ�Ѿ���һ��ȫ������*/
		if (level == num.size()) {
			res.push_back(out);
			return;
		}
		for (int i = 0; i < num.size(); ++i) {
			if (visited[i] == 1) {
				continue;
			}
			visited[i] = 1;
			out.push_back(num[i]);
			permuteDFS(num, level + 1, out, visited, res);
			out.pop_back();
			visited[i] = 0;
		}
	}
};

//��2��STL����ȫ���к���
class Solution2 {
public:
	vector<vector<int>> permute(vector<int>& num) {
		vector<vector<int> > res;
		sort(num.begin(), num.end());
		res.push_back(num);
		while (next_permutation(num.begin(), num.end())) {
			res.push_back(num);
		}
		return res;
	}
};
