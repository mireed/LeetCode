/*leetcode 543. Diameter of Binary Tree
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of 
the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
1
/ \
2   3
/ \
4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.

换一种角度来看，其实就是根结点的左右两个子树的深度之和。那么只要对每一个结点求出其左右子树深度之和，这个值作为一个候选值，然后再对左右子结点
分别调用求直径对递归函数，这三个值相互比较，取最大的值更新结果res，因为直径不一定会经过根结点，所以才要对左右子结点再分别算一次。为了减少重复
计算，我们用哈希表建立每个结点和其深度之间的映射，这样某个结点的深度之前计算过了，就不用再次计算了
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int diameterOfBinaryTree(TreeNode* root) {
	int res = 0;
	maxDepth(root, res);
	return res;
}

int maxDepth(TreeNode* node, int& res) {
	unordered_map<TreeNode*, int> m;
	if (!node) {
		return 0;
	}
	if (m.count(node)) {
		return m[node];
	}
	int left = maxDepth(node->left, res);
	int right = maxDepth(node->right, res);
	res = max(res, left + right);
	return m[node] = (max(left, right) + 1);
}
