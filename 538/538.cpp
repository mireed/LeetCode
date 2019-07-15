/*LEETCODE 538. Convert BST to Greater Tree
  Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original 
BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:
Input: The root of a Binary Search Tree like this:
5
/   \
2     13
Output: The root of a Greater Tree like this:
18
/   \
20     13

BST或者是一棵空树，或者是具有下列性质的二叉树： 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值； 
若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值； 它的左、右子树也分别为二叉排序树。中序遍历左根右从小到大排序，
将中序遍历左根右的顺序逆过来，变成右根左的顺序，这样就可以反向计算累加和sum，同时更新结点值
*/

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : 
		val(x), left(NULL), right(NULL) {}
};

TreeNode* convertBST(TreeNode* root) {
	int sum = 0;
	convertBSTcore(root, sum);
	return root;
}

void convertBSTcore(TreeNode* &node, int &sum) {
	if (!node) {
		return;
	}
	convertBSTcore(node->right, sum);
	node->val += sum;
	sum = node->val;
	convertBSTcore(node->left, sum);
}