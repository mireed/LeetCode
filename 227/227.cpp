/*leetcode 227. Basic Calculator I
  
  Implement a basic calculator to evaluate a simple expression string.
The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . 
The integer division should truncate toward zero.
  
  Example 1:
Input: "3+2*2"
Output: 7
  Example 2:
Input: " 3/2 "
Output: 1
  Example 3:
Input: " 3+5 / 2 "
Output: 5

  Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.

�������ȼ���
ʹ��һ��ջ�������֣����������֮ǰ�ķ����Ǽӻ������ô�ѵ�ǰ����ѹ��ջ�У�ע������Ǽ��ţ�����뵱ǰ���ֵ��෴����
��Ϊ�����൱�ڼ���һ���෴�������֮ǰ�ķ����ǳ˻������ô��ջ��ȡ��һ�����ֺ͵�ǰ���ֽ��г˻�������㣬�ٰѽ��ѹ��ջ�У�
��ô���һ����������еĳ˻�����������ˣ��ٰ�ջ�����е����ֶ��������������ս����
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int calculate(string s) {
	stack<int> temp;
	long res = 0, sum = 0;
	char op = '+';
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0') {
			sum = sum * 10 + (s[i] - '0');
		}
		if ((s[i] < '0' && s[i] != ' ') || i == s.size() - 1) {
			if (op == '+') {
				temp.push(sum);
			}
			if (op == '-') {
				temp.push(-sum);
			}
			if (op == '*' || op == '/') {
				long t = (op == '*') ? temp.top() * sum : temp.top() / sum;
				temp.pop();
				temp.push(t);
			}
			op = s[i];
			sum = 0;
		}
	}
	while (!temp.empty()) {
		res += temp.top();
		temp.pop();
	}
	return res;
}


int main() {
	string str;
	cout << "����������ַ�����" << endl;
	getline(cin, str);
	int result = calculate(str);
	cout << result << endl;
	system("pause");
	return 0;
}
