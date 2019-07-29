/*leetcode 160. Intersection of Two Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins.
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8

法1：分别遍历两个链表，得到分别对应的长度。然后求长度的差值，把较长的那个链表向后移动这个差值的个数，然后一一比较即可
法2：用环的思想来做，让两条链表分别从各自的开头开始往后遍历，当其中一条遍历到末尾时，我们跳到另一个条链表的开头继续遍历。两个指针最终会
    相等，而且只有两种情况，一种情况是在交点处相遇，另一种情况是在各自的末尾的空节点处相等。为什么一定会相等呢，因为两个指针走过的路程相同，
	是两个链表的长度之和，所以一定会相等
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//法1
ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
	if (!headA || !headB) return NULL;
	int lenA = getLength(headA), lenB = getLength(headB);
	if (lenA < lenB) {
		for (int i = 0; i < lenB - lenA; ++i) headB = headB->next;
	}
	else {
		for (int i = 0; i < lenA - lenB; ++i) headA = headA->next;
	}
	while (headA && headB && headA != headB) {
		headA = headA->next;
		headB = headB->next;
	}
	return (headA && headB) ? headA : NULL;
}
int getLength(ListNode* head) {
	int cnt = 0;
	while (head) {
		++cnt;
		head = head->next;
	}
	return cnt;
}

//法2
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
	if (!headA || !headB) {
		return NULL;
	}
	ListNode* a = headA, *b = headB;
	while (a != b) {
		a = a ? a->next : headB;
		b = b ? b->next : headA;
	}
	return a;
}