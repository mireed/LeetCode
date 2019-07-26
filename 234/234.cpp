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

��1���Ȱ�˳������еĽ��ֵ�����뵽һ��ջ stack �Ȼ������ջ�ĺ����ȳ������ԣ��Ϳ��԰�˳���ĩβȡ�����ֵ�ˣ���ʱ�ٴ�ͷ����һ������
     �Ϳ��ԱȽϻ��ĵĶ�Ӧλ���ˣ�����ֱͬ�ӷ��� false ����
��2�����ÿ���ָ�룬�ÿ���ָ�����е��ԭ���� fast �� slow ����ָ�룬ÿ�ο�ָ������������ָ����һ�����ȿ�ָ������ʱ����ָ���λ�þ����е㡣
     ����Ҫ��ջ��ÿ����ָ����һ��������ֵ����ջ�У��ȵ����е�ʱ�������ǰ��ζ�����ջ���ˣ�����ջ�ĺ���ȳ������ʣ��Ϳ��Ժͺ���������
	 ���Ķ�Ӧ��˳��Ƚ���
��3����O(1)�Ŀռ䣬���ҵ��е�󣬽����ε�����תһ�£��Ϳ��԰��ջ��ĵ�˳��Ƚ�
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
	while (last->next) {//������ķ�ת
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

