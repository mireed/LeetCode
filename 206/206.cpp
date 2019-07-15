/*leetcode 206. Reverse Linked List
Reverse a singly linked list.

Example:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

迭代:利用变量的原值推算出变量的一个新值.如果递归是自己调用自己的话,迭代就是A不停的调用B.(在原链表之前建立一个空的newHead，
     因为首节点会变，然后从head开始，将之后的一个节点移到newHead之后，重复此操作直到head成为末节点为止)
递归:程序调用自身的编程技巧称为递归,是函数自己调用自己.(不断的进入递归函数，直到head指向倒数第二个节点，因为head指向空或者
     是最后一个结点都直接返回了，newHead则指向对head的下一个结点调用递归函数返回的头结点，此时newHead指向最后一个结点，然后
	 head的下一个结点的next指向head本身，这个相当于把head结点移动到末尾的操作，因为是回溯的操作，所以head的下一个结点总是在
	 上一轮被移动到末尾了，但head之后的next还没有断开，所以可以顺势将head移动到末尾，再把next断开，最后返回newHead即可)
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : 
		val(x), next(NULL) {}
};

//迭代
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

//递归
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