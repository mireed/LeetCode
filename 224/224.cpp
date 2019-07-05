/*leetcode 224. Basic Calculator
  Implement a basic calculator to evaluate a simple expression string.The expression string may contain open 
( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

  Example 1:
Input: "1 + 1"
Output: 2
  Example 2:
Input: " 2-1 + 2 "
Output: 3
  Example 3:
Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
  
  Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.
    
	��һ��ջ���������㣬�ø�����sign����ʾ��ǰ�ķ��š������������ַ���s��
������������֣����ڿ����Ǹ���λ������������Ҫ��whileѭ����֮������ֶ���������Ȼ����sign*num�����½��res��
��������˼Ӻţ���sign��Ϊ1����������˸��ţ���Ϊ-1��
��������������ţ���ѵ�ǰ���res�ͷ���signѹ��ջ��res����Ϊ0��sign����Ϊ1��
��������������ţ����res����ջ���ķ��ţ�ջ��Ԫ�س�ջ�����res����ջ�������֣�ջ��Ԫ�س�ջ��
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int calculate(string s) {
	stack<int> temp;
	int res = 0;
	int sign = 1;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		if (c >= '0') {
			int num = 0;
			while (i < s.size() && s[i] >= '0') {
				num = num * 10 + (s[i++] - '0');
			}
			res += num * sign;
			--i;
		}
		else if (c == '+') {
			sign = 1;
		}
		else if (c == '-') {
			sign = -1;
		}
		else if (c == '(') {
			temp.push(res);
			temp.push(sign);
			res = 0;
			sign = 1;
		}
		else if(c == ')'){
			res *= temp.top();
			temp.pop();
			res += temp.top();
			temp.pop();
		}
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
