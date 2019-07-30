/*leetcode 94. Binary Tree Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
1
\
2
/
3
Output: [1,3,2]

·¨1£ºµÝ¹é
·¨2£ºµü´ú,½èÖú¸¨ÖúÕ»
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//µÝ¹é
class Solution1 {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		inorder(root, res);
		return res;
	}
	void inorder(TreeNode* root, vector<int> &res) {
		if (root == NULL) {
			return;
		}
		if (root->left) {
			inorder(root->left, res);
		}
		res.push_back(root->val);
		if (root->right) {
			inorder(root->right, res);
		}
	}
};

//µü´ú
class Solution2 {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		vector<int> res;
		TreeNode* p = root;
		while (p || !s.empty()) {
			while (p) {
				s.push(p);
				p = p->left;
			}
			p = s.top();
			s.pop();
			res.push_back(p->val);
			p = p->right;
		}
		return res;
	}
};