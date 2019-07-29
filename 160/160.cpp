/*leetcode 160. Intersection of Two Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins.
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8

��1���ֱ�������������õ��ֱ��Ӧ�ĳ��ȡ�Ȼ���󳤶ȵĲ�ֵ���ѽϳ����Ǹ���������ƶ������ֵ�ĸ�����Ȼ��һһ�Ƚϼ���
��2���û���˼������������������ֱ�Ӹ��ԵĿ�ͷ��ʼ���������������һ��������ĩβʱ������������һ��������Ŀ�ͷ��������������ָ�����ջ�
    ��ȣ�����ֻ�����������һ��������ڽ��㴦��������һ��������ڸ��Ե�ĩβ�Ŀսڵ㴦��ȡ�Ϊʲôһ��������أ���Ϊ����ָ���߹���·����ͬ��
	����������ĳ���֮�ͣ�����һ�������
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//��1
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

//��2
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