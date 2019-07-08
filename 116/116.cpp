/*leetcode 116. Populating Next Right Pointers in Each Node
  You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. 
The binary tree has the following definition:
struct Node {
int val;
Node *left;
Node *right;
Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer 
should be set to NULL.Initially, all next pointers are set to NULL.

input:树的前序遍历:根左右
       ID: 1 2 3 4 5 6 7
	   VAL:1 2 4 5 3 6 7
	   
output：树的层次遍历
  (1)递归：由于是完全二叉树，所以若节点的左子结点存在的话，其右子节点必定存在，所以左子结点的next指针可以直接指向其右子节点，
  对于其右子节点的处理方法是， 判断其父节点的next是否为空，若不为空，则指向其next指针指向的节点的左子结点，若为空则指向NULL
  (2)非递归:用queue来辅助，由于是层序遍历，每层的节点都按顺序加入queue中，而每当从queue中取出一个元素时，将其next指针指向queue中
  下一个节点即可，我们对于每层的开头元素开始遍历之前，先统计一下该层的总个数，用个for循环，这样for循环结束的时候，我们就知道该层已经被遍历完了
  (3)用两个指针start和cur，其中start标记每一层的起始节点，cur用来遍历该层的节点
  */

#include <iostream>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;
	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

//递归解法
class Solution1 {
public:
	Node* connect(Node* root) {
		if (!root) {
			return NULL;
		}
		if (root->left) {
			root->left->next = root->right;
		}
		if (root->right) {
			if (root->next == NULL) {
				root->right->next = NULL;
			}
			else {
				root->right->next = root->next->left;
			}
		}
		connect(root->left);
		connect(root->right);
		return root;
	}
};

//非递归解法
class Solution2 {
public:
	Node* connect(Node* root) {
		if (!root) {
			return NULL;
		}
		queue <Node*> q;
		q.push(root);
		while (!q.empty()) {
			int n = q.size();
			for (int i = 0; i < n; i++) {
				Node* temp = q.front();
				q.pop();
				if (i < n - 1) {
					temp->next = q.front();
				}
				if (temp->left) {
					q.push(temp->left);
				}
				if (temp->right) {
					q.push(temp->right);
				}
			}
		}
		return root;
	}
};