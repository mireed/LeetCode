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
逆波兰表达式：第一个出现的运算符，其前面必有两个数字，当这个运算符和之前两个数字完成运算后从原数组中删去，
             把得到一个新的数字插入到原来的位置，继续做相同运算，直至整个数组变为一个数字
			 用栈来做,从从前往后遍历数组，遇到数字则压入栈中，遇到符号，则把栈顶的两个数字拿出来运算，
			 把结果再压入栈中，直到遍历完整个数组，栈顶数字即为最终答案。
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
	cout << "请输入字符串：" << endl;
	while (cin >> str) {
		test.push_back(str);
	}
	int res = evalRPN(test);
	cout << res << endl;
	system("pause");
	return 0;
}