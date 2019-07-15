/*leetcode 226. Invert Binary Tree
Invert a binary tree.

Example:
Input:
    4
  /   \
 2     7
/ \   / \
1  3 6  9
Output:
   4
 /   \
7     2
/ \   / \
9   6 3   1

µ›πÈ”Î∑«µ›πÈ
*/

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : 
		val(x), left(NULL), right(NULL) {}
};

//µ›πÈ
class Solution1 {
public:
	TreeNode* invertTree1(TreeNode* root) {
		if (!root) {
			return NULL;
		}
		TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;
		invertTree1(root->left);
		invertTree1(root->right);
		return root;
	}
};

//∑«µ›πÈ£¨”√queue¿¥∏®÷˙
class Solution2 {
public:
	TreeNode* invertTree2(TreeNode* root) {
		if (!root) {
			return NULL;
		}
		queue<TreeNode*> q{ {root} };
		while (!q.empty()) {
			TreeNode* f = q.front();
			q.pop();
			TreeNode* t = f->left;
			f->left = f->right;
			f->right = t;
			if (f->left) {
				q.push(f->left);
			}
			if (f->right) {
				q.push(f->right);
			}
		}
		return root;
	}
};