/*leetcode 102. Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
return its level order traversal as:
[
[3],
[9,20],
[15,7]
]

二叉树的层次遍历有递归和非递归两种解法，递归的关键在于需要一个二维数组和一个变量level；非递归是BFS的经典应用，利用一个queue来做；
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//递归
class Solution1 {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int> > res;
		levelorder(root, 0, res);
		return res;
	}
	void levelorder(TreeNode* node, int level, vector<vector<int> >& res) {
		if (!node) {
			return;
		}
		if (res.size() == level) {
			res.push_back({});
		}
		res[level].push_back(node->val);
		if (node->left) {
			levelorder(node->left, level + 1, res);
		}
		if (node->right) {
			levelorder(node->right, level + 1, res);
		}
	}
};

//非递归
class Solution2 {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (!root) {
			return{};
		}
		vector<vector<int> > res;
		queue<TreeNode* > q{ {root} };
		while (!q.empty()) {
			vector<int> onelevel;
			for (int i = q.size(); i > 0; --i) {
				TreeNode* t = q.front();
				q.pop();
				onelevel.push_back(t->val);
				if (t->left) {
					q.push(t->left);
				}
				if (t->right) {
					q.push(t->right);
				}
			}
			res.push_back(onelevel);
		}
		return res;
	}
};