/*leetcode 21. Merge Two Sorted Lists
  Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the 
first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

�½�һ������Ȼ��Ƚ����������е�Ԫ��ֵ���ѽ�С���Ǹ������������У�����������������ĳ��ȿ��ܲ�ͬ���������ջ���һ����������ɲ�������Ԫ�أ�
��ֱ����һ��δ��ɵ�����ֱ�������������ĩβ
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :
		val(x), next(NULL) {}
};


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode *l = new ListNode(-1), *cur = l;
	if (l1 == NULL) {
		l->next = l2;
	}
	if (l2 == NULL) {
		l->next = l1;
	}
	while (l1 && l2) {
		if (l1->val < l2->val) {
			cur->next = l1;
			l1 = l1->next;
		}
		else {
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}
	cur->next = l1 ? l1 : l2;
	return l->next;
}
