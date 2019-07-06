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

考虑优先级：
使用一个栈保存数字，如果该数字之前的符号是加或减，那么把当前数字压入栈中，注意如果是减号，则加入当前数字的相反数，
因为减法相当于加上一个相反数。如果之前的符号是乘或除，那么从栈顶取出一个数字和当前数字进行乘或除的运算，再把结果压入栈中，
那么完成一遍遍历后，所有的乘或除都运算完了，再把栈中所有的数字都加起来就是最终结果了
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
	cout << "请输入计算字符串：" << endl;
	getline(cin, str);
	int result = calculate(str);
	cout << result << endl;
	system("pause");
	return 0;
}
