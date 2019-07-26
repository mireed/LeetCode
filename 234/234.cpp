/*leetcode 234. Palindrome Linked List
Given a singly linked list, determine if it is a palindrome.

Example 1:
Input: 1->2
Output: false
Example 2:
Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

法1：先按顺序把所有的结点值都存入到一个栈 stack 里，然后利用栈的后入先出的特性，就可以按顺序从末尾取出结点值了，此时再从头遍历一遍链表，
     就可以比较回文的对应位置了，若不同直接返回 false 即可
法2：利用快慢指针，用快慢指针找中点的原理是 fast 和 slow 两个指针，每次快指针走两步，慢指针走一步，等快指针走完时，慢指针的位置就是中点。
     还需要用栈，每次慢指针走一步，都把值存入栈中，等到达中点时，链表的前半段都存入栈中了，由于栈的后进先出的性质，就可以和后半段链表按照
	 回文对应的顺序比较了
法3：用O(1)的空间，在找到中点后，将后半段的链表翻转一下，就可以按照回文的顺序比较
*/

#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome1(ListNode* head) {
	stack<int> s;
	ListNode* cur = head;
	while (cur) {
		s.push(cur->val);
		cur = cur->next;
	}
	while (head) {
		int temp = s.top();
		s.pop();
		if (head->val != temp) {
			return false;
		}
		head = head->next;
	}
	return true;
}

bool isPalindrome2(ListNode* head) {
	if (!head || !head->next) {
		return true;
	}
	ListNode* slow = head;
	ListNode* fast = head;
	stack<int> s{ { head->val } };
	while (fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
		s.push(slow->val);
	}
	if (!fast->next) {
		s.pop();
	}
	while (slow->next) {
		slow = slow->next;
		int temp = s.top();
		s.pop();
		if (temp != slow->val) {
			return false;
		}
	}
	return true;
}

bool isPalindrome3(ListNode* head) {
	if (!head || !head->next) {
		return true;
	}
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	ListNode* last = slow->next;
	ListNode* pre = head;
	while (last->next) {//单链表的反转
		ListNode *tmp = last->next;
		last->next = tmp->next;
		tmp->next = slow->next;
		slow->next = tmp;
	}
	while (slow->next) {
		slow = slow->next;
		if (slow->val != pre->val) {
			return false;
		}
		pre = pre->next;
	}
	return true;
}

