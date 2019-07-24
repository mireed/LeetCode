/*leetcode 155. Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

��1��ʹ������ջ��ʵ�֣�һ��ջ����˳��洢push���������ݣ���һ����������ֹ�����Сֵ
��2��ֻ�õ���һ��ջ������Ҫһ�����ͱ���min_val����¼��ǰ��Сֵ����ʼ��Ϊ�������ֵ��Ȼ�������Ҫ��ջ������С�ڵ��ڵ�ǰ��Сֵmin_val����ô��
     min_valѹ��ջ�����ҽ�min_val����Ϊ��ǰ���֡��ڳ�ջ����ʱ���Ƚ�ջ��Ԫ���Ƴ�ջ�����жϸ�Ԫ���Ƿ��min_val��ȣ���ȵĻ����ǽ�min_val����
	 Ϊ��ջ��Ԫ�أ��ٽ���ջ��Ԫ���Ƴ�ջ����
*/

#include <iostream>
#include <stack>

using namespace std;

class MinStack1 {
public:
	/** initialize your data structure here. */
	MinStack1() {

	}

	void push(int x) {
		s1.push(x);
		if (s2.empty() || x <= s2.top()) {
			s2.push(x);
		}
	}

	void pop() {
		if (s1.top() == s2.top()) {
			s2.pop();
		}
		s1.pop();
	}

	int top() {
		return s1.top();
	}

	int getMin() {
		return s2.top();
	}
private:
	stack<int> s1, s2;
};

//��2
class MinStack2 {
public:
	/** initialize your data structure here. */
	MinStack2() {
		min_val = INT_MAX;
	}

	void push(int x) {
		if (x <= min_val) {
			s.push(min_val);
			min_val = x;
		}
		s.push(x);
	}

	void pop() {
		int temp = s.top();
		s.pop();
		if (temp == min_val) {
			min_val = s.top();
			s.pop();
		}
	}

	int top() {
		return s.top();
	}

	int getMin() {
		return min_val;
	}
private:
	stack<int> s;
	int min_val;
};
