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

法1：使用两个栈来实现，一个栈来按顺序存储push进来的数据，另一个用来存出现过的最小值
法2：只用到了一个栈，还需要一个整型变量min_val来记录当前最小值，初始化为整型最大值，然后如果需要进栈的数字小于等于当前最小值min_val，那么将
     min_val压入栈，并且将min_val更新为当前数字。在出栈操作时，先将栈顶元素移出栈，再判断该元素是否和min_val相等，相等的话我们将min_val更新
	 为新栈顶元素，再将新栈顶元素移出栈即可
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

//法2
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
