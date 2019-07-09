/*leetcode 29. Divide Two Integers
  Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
Return the quotient after dividing dividend by divisor.The integer division should truncate toward zero.

  Example 1:
Input: dividend = 10, divisor = 3
Output: 3
  Example 2:
Input: dividend = 7, divisor = -3
Output: -2

  Note:
Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, 
assume that your function returns 231 − 1 when the division result overflows.

利用位操作Bit Operation：如果被除数大于或等于除数，则进行如下循环，定义变量t等于除数，定义计数p，当t的两倍小于等于被除数时，进行如下循环，t扩
大一倍，p扩大一倍，然后更新res和m。因为输入的都是int型，比如被除数是-2147483648，在int范围内，当除数是-1时，结果就超出了int范围，需要返回
INT_MAX，所以对于这种情况就在开始用if判定，将其和除数为0的情况放一起判定，返回INT_MAX。然后还要根据被除数和除数的正负来确定返回值的正负，这里
我们采用长整型long来完成所有的计算，最后返回值乘以符号即可
*/

#include <iostream>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
			return INT_MAX;
		}
		long long m = abs((long long)dividend);
		long long n = abs((long long)divisor);
		long long res = 0;
		int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
		if (n == 1) {
			return (sign == -1) ? -m : m;
		}
		while (m >= n) {
			long long t = n, p = 1;
			while (m >= (t << 1)) {
				t <<= 1;
				p <<= 1;
			}
			res += p;
			m -= t;
		}
		return sign == 1 ? res : -res;
	}
};

int main() {
	int a, b, result;
	cout << "请输入被除数和除数：" << endl;
	cin >> a >> b;
	Solution test;
	result = test.divide(a, b);
	cout << result << endl;
	system("pause");
	return 0;
}