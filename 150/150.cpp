/*leetcode 150. Evaluate Reverse Polish Notation
  Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.

  Note:
Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.

  Example 1:
Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
  Example 2:
Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
  Example 3:
Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation:
((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
�沨�����ʽ����һ�����ֵ����������ǰ������������֣�������������֮ǰ�����������������ԭ������ɾȥ��
             �ѵõ�һ���µ����ֲ��뵽ԭ����λ�ã���������ͬ���㣬ֱ�����������Ϊһ������
			 ��ջ����,�Ӵ�ǰ����������飬����������ѹ��ջ�У��������ţ����ջ�������������ó������㣬
			 �ѽ����ѹ��ջ�У�ֱ���������������飬ջ�����ּ�Ϊ���մ𰸡�
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int evalRPN(vector<string>& tokens) {
	stack<int> temp;
	int n = tokens.size();
	for (int i = 0; i < n; ++i) {
		if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*"  && tokens[i] != "/") {
			temp.push(stoi(tokens[i]));
		}
		else {
			int num2 = temp.top();
			temp.pop();
			int num1 = temp.top();
			temp.pop();
			if (tokens[i] == "+") {
				temp.push(num1 + num2);
			}
			if (tokens[i] == "-") {
				temp.push(num1 - num2);
			}
			if (tokens[i] == "*") {
				temp.push(num1 * num2);
			}
			if (tokens[i] == "/") {
				temp.push(num1 / num2);
			}
		}
	}
	return temp.top();
}

int main() {
	vector<string> test;
	string str;
	cout << "�������ַ�����" << endl;
	while (cin >> str) {
		test.push_back(str);
	}
	int res = evalRPN(test);
	cout << res << endl;
	system("pause");
	return 0;
}