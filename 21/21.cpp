/*leetcode 21. Merge Two Sorted Lists
  Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the 
first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

新建一个链表，然后比较两个链表中的元素值，把较小的那个链到新链表中，由于两个输入链表的长度可能不同，所以最终会有一个链表先完成插入所有元素，
则直接另一个未完成的链表直接链入新链表的末尾
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
