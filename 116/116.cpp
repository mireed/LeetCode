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

input:����ǰ�����:������
       ID: 1 2 3 4 5 6 7
	   VAL:1 2 4 5 3 6 7
	   
output�����Ĳ�α���
  (1)�ݹ飺��������ȫ���������������ڵ�����ӽ����ڵĻ��������ӽڵ�ض����ڣ��������ӽ���nextָ�����ֱ��ָ�������ӽڵ㣬
  ���������ӽڵ�Ĵ������ǣ� �ж��丸�ڵ��next�Ƿ�Ϊ�գ�����Ϊ�գ���ָ����nextָ��ָ��Ľڵ�����ӽ�㣬��Ϊ����ָ��NULL
  (2)�ǵݹ�:��queue�������������ǲ��������ÿ��Ľڵ㶼��˳�����queue�У���ÿ����queue��ȡ��һ��Ԫ��ʱ������nextָ��ָ��queue��
  ��һ���ڵ㼴�ɣ����Ƕ���ÿ��Ŀ�ͷԪ�ؿ�ʼ����֮ǰ����ͳ��һ�¸ò���ܸ������ø�forѭ��������forѭ��������ʱ�����Ǿ�֪���ò��Ѿ�����������
  (3)������ָ��start��cur������start���ÿһ�����ʼ�ڵ㣬cur���������ò�Ľڵ�
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

//�ݹ�ⷨ
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

//�ǵݹ�ⷨ
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