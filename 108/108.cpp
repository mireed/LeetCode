/*leetcode 108. Convert Sorted Array to Binary Search Tree
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node 
never differ by more than 1.

Example:
Given the sorted array: [-10,-3,0,5,9],
One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

0
/ \
-3   9
/   /
-10  5

����������תΪ��������������ν��������������һ��ʼ��������<��<�ҵ����ԣ��������������������������Ļ����õ��ľ���һ�����������ˡ�
��ô�����������ڵ�Ӧ��������������м�㣬���м��ֿ�Ϊ���������������飬�ڷֱ��ҳ����м����Ϊԭ�м������������ӽڵ㣬�����
���ֲ��ҷ��ĺ���˼��
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty()) {
			return NULL;
		}
		int mid = nums.size() / 2;
		TreeNode* temp = new TreeNode(nums[mid]);
		vector<int> left(nums.begin(), nums.begin() + mid), right(nums.begin() + mid + 1, nums.end());
		temp->left = sortedArrayToBST(left);
		temp->right = sortedArrayToBST(right);
		return temp;
	}
}