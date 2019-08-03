/*leetcode 230. Kth Smallest Element in a BST
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
Note:
You may assume k is always valid, 1 �� k �� BST's total elements.

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

���������С��������������ȱ�����������С�Ľ�㣬��һ����������ÿ����һ����㣬����������1��������������kʱ�����ص�ǰ���ֵ����
�еݹ�ͷǵݹ����ֽⷨ
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

//�ǵݹ飬����ջ
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

//�ݹ�
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