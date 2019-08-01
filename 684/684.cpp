/*leetcode 684. Redundant Connection
In this problem, a tree is an undirected graph that is connected and has no cycles.The given input is a graph that started as a 
tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices 
chosen from 1 to N, and was not an edge that already existed.The resulting graph is given as a 2D-array of edges. Each element of
edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.Return an edge that can be removed 
so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 
2D-array. The answer edge [u, v] should be in the same format, with u < v.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
1
/ \
2 - 3
Example 2:
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
|   |
4 - 3

Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

无向图，删掉组成环的最后一条边
法1：DFS递归。每加入一条边，就进行环检测，一旦发现了环，就返回当前边。对于无向图，用邻接表来保存，建立每个结点和其所有邻接点的映射，
    由于两个结点之间不算有环，所以要避免这种情况 1->{2}, 2->{1}的死循环，用一个变量pre记录上一次递归的结点，比如上一次遍历的是结点1，
	那么在遍历结点2的邻接表时，就不会再次进入结点1了，这样有效的避免了死循环，使其能返回正确的结果
法2：BFS迭代。
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution {
public:
	vector<int> findRedundantConnection1(vector<vector<int>>& edges) {
		unordered_map<int, unordered_set<int>> m;
		for (auto edge : edges) {
			if (DFS1(edge[0], edge[1], m, -1)) {
				return edge;
			}
			m[edge[0]].insert(edge[1]);
			m[edge[1]].insert(edge[0]);
		}
		return{};
	}
	bool DFS1(int cur, int target, unordered_map<int, unordered_set<int>>& m, int pre) {
		if (m[cur].count(target)) {
			return true;
		}
		for (auto num : m[cur]) {
			if (num == pre) {
				continue;
			}
			if (DFS1(num, target, m, cur)) {
				return true;
			}
		}
		return false;
	}
};

int main() {
	vector<int> temp, result;
	vector<vector<int>> test;
	int s;
	bool flag = true;
	while (flag) {
		do {
			cin >> s;
			if (!cin) {
				flag = false;
				break;
			}
			temp.push_back(s);
		} while (cin.get() != '\n');
		if (flag) {
			test.push_back(temp);
			temp.clear();
		}
	}
	Solution s1;
	result = s1.findRedundantConnection1(test);
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}
	system("pause");
	return 0;
}