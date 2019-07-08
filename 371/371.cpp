/*371. Sum of Two Integers
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:
Input: a = 1, b = 2
Output: 3
Example 2:
Input: a = -2, b = 3
Output: 1

位运算，不考虑进位时用异或实现，进位用与运算实现
*/

#include <iostream>

using namespace std;

int getSum(int a, int b) {
	if (b == 0) {
		return a;
	}
	int sum = a ^ b;
	int carry = (a & b & 0x7fffffff) << 1;
	return getSum(sum, carry);
}

int main() {
	int a, b;
	cin >> a >> b;
	int sum = getSum(a, b);
	cout << sum << " ";
	cout << endl;
	system("pause");
	return 0;
}