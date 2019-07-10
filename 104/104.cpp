/*leetcode 104. Maximum Depth of Binary Tree
  Given a binary tree, find its maximum depth.The maximum depth is the number of nodes along the longest path from the root 
node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:
Given binary tree [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
return its depth = 3.

DFS递归或者层次遍历二叉树计算层数
*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};

//DFS
class Solution1 {
public:
	int maxDepth1(TreeNode* root) {
		if (!root) {
			return 0;
		}
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
};

//层次遍历,用queue来实现
class Solution2 {
public:
	int maxDepth2(TreeNode* root) {
		if (!root) {
			return 0;
		}
		int count = 0;
		queue<TreeNode*> q{ {root} };
		while (!q.empty()) {
			count++;
			for (int i = q.size(); i > 0; --i) {
				TreeNode* t = q.front();
				q.pop();
				if (t->left) {
					q.push(t->left);
				}
				if (t->right) {
					q.push(t->right);
				}
			}
		}
		return count;
	}
};