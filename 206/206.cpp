/*leetcode 206. Reverse Linked List
Reverse a singly linked list.

Example:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

����:���ñ�����ԭֵ�����������һ����ֵ.����ݹ����Լ������Լ��Ļ�,��������A��ͣ�ĵ���B.(��ԭ����֮ǰ����һ���յ�newHead��
     ��Ϊ�׽ڵ��䣬Ȼ���head��ʼ����֮���һ���ڵ��Ƶ�newHead֮���ظ��˲���ֱ��head��Ϊĩ�ڵ�Ϊֹ)
�ݹ�:�����������ı�̼��ɳ�Ϊ�ݹ�,�Ǻ����Լ������Լ�.(���ϵĽ���ݹ麯����ֱ��headָ�����ڶ����ڵ㣬��Ϊheadָ��ջ���
     �����һ����㶼ֱ�ӷ����ˣ�newHead��ָ���head����һ�������õݹ麯�����ص�ͷ��㣬��ʱnewHeadָ�����һ����㣬Ȼ��
	 head����һ������nextָ��head��������൱�ڰ�head����ƶ���ĩβ�Ĳ�������Ϊ�ǻ��ݵĲ���������head����һ�����������
	 ��һ�ֱ��ƶ���ĩβ�ˣ���head֮���next��û�жϿ������Կ���˳�ƽ�head�ƶ���ĩβ���ٰ�next�Ͽ�����󷵻�newHead����)
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : 
		val(x), next(NULL) {}
};

//����
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* newHead = NULL;
		while (head) {
			ListNode* t = head->next;
			head->next = newHead;
			newHead = head;
			head = t;
		}
		return newHead;
	}
};

//�ݹ�
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) {
			return head;
		}
		ListNode* newHead = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return newHead;
	}
};