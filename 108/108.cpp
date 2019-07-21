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

将有序数组转为二叉搜索树，所谓二叉搜索树，是一种始终满足左<根<右的特性，如果将二叉搜索树按中序遍历的话，得到的就是一个有序数组了。
那么反过来，根节点应该是有序数组的中间点，从中间点分开为左右两个有序数组，在分别找出其中间点作为原中间点的左右两个子节点，这就是
二分查找法的核心思想
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