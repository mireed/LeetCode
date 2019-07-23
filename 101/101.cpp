/*leetcode 101. Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
1
/ \
2   2
/ \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
1
/ \
2   2
\   \
3    3

法1：递归
法2：迭代，借助一个队列来实现
*/

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root) {
			return true;
		}
		return isSymmetricCore(root->left, root->right);
	}
	bool isSymmetricCore(TreeNode* left, TreeNode* right) {
		if (!left && !right) {
			return true;
		}
		if ((!left && right) || (left && !right) || (left->val != right->val)) {
			return false;
		}
		return isSymmetricCore(left->left, right->right) && isSymmetricCore(left->right, right->left);
	}
};

class Solution2 {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root) {
			return true;
		}
		queue<TreeNode*> q1, q2;
		q1.push(root->left);
		q2.push(root->right);
		while (!q1.empty() && !q2.empty()) {
			TreeNode* temp1 = q1.front();
			q1.pop();
			TreeNode* temp2 = q2.front();
			q2.pop();
			if (!temp1 && !temp2) {
				continue;
			}
			if ((!temp1 && temp2) || (temp1 && !temp2)){
			    return false;
            }
			if (temp1->val != temp2->val) {
				return false;
			}
			q1.push(temp1->left);
			q1.push(temp1->right);
			q2.push(temp2->right);
			q2.push(temp2->left);
		}
		return true;
	}
};