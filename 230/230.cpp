/*leetcode 230. Kth Smallest Element in a BST
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:
Input: root = [3,1,4,null,2], k = 1
3
/ \
1   4
\
2
Output: 1
Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
5
/ \
3   6
/ \
2   4
/
1
Output: 3

中序遍历从小到大，中序遍历最先遍历到的是最小的结点，用一个计数器，每遍历一个结点，计数器自增1，当计数器到达k时，返回当前结点值即可
有递归和非递归两种解法
*/

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//非递归，借助栈
class Solution1 {
public:
	int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*> s;
		int count = 0;
		TreeNode* p = root;
		while (p || !s.empty()) {
			while (p) {
				s.push(p);
				p = p->left;
			}
			p = s.top();
			s.pop();
			++count;
			if (count == k) {
				return p->val;
			}
			p = p->right;
		}
		return 0;
	}
};

//递归
class Solution2 {
public:
	int kthSmallest(TreeNode* root, int k) {
		return kthSmallestDFS(root, k);
	}
	int kthSmallestDFS(TreeNode* root, int& k) {
		if (!root) {
			return -1;
		}
		int val = kthSmallestDFS(root->left, k);
		if (k == 0) {
			return val;
		}
		if (--k == 0) {
			return root->val;
		}
		return kthSmallestDFS(root->right, k);
	}
};