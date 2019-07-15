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

BST������һ�ÿ����������Ǿ����������ʵĶ������� ���������������գ��������������н���ֵ��С�����ĸ�����ֵ�� 
���������������գ��������������н���ֵ���������ĸ�����ֵ�� ������������Ҳ�ֱ�Ϊ�����������������������Ҵ�С��������
�������������ҵ�˳�������������Ҹ����˳�������Ϳ��Է�������ۼӺ�sum��ͬʱ���½��ֵ
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