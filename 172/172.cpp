/*leetcode 172. Factorial Trailing Zeroes
Given an integer n, return the number of trailing zeroes in n!.

Example 1:
Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:
Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Note: Your solution should be in logarithmic time complexity.

让求一个数的阶乘末尾0的个数，也就是要找乘数中10的个数，而10可分解为2和5，可知2的数量又远大于5的数量，
那么此题即便为找出5的个数。仍需注意的一点就是，像25,125，这样的不只含有一个5的数字需要考虑进去。
*/

#include <iostream>

using namespace std;

int trailingZeroes1(int n) {
	int res = 0;
	while (n) {
		res += n / 5;
		n /= 5;
	}
	return res;
}

//递归
int trailingZeroes2(int n) {
	return n == 0 ? 0 : n / 5 + trailingZeroes2(n / 5);
}

int main() {
	int test;
	cin >> test;
	cout << trailingZeroes1(test) << endl;
	cout << trailingZeroes2(test) << endl;
	system("pause");
	return 0;
}

