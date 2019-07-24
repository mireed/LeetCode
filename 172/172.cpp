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

����һ�����Ľ׳�ĩβ0�ĸ�����Ҳ����Ҫ�ҳ�����10�ĸ�������10�ɷֽ�Ϊ2��5����֪2��������Զ����5��������
��ô���⼴��Ϊ�ҳ�5�ĸ���������ע���һ����ǣ���25,125�������Ĳ�ֻ����һ��5��������Ҫ���ǽ�ȥ��
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

//�ݹ�
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

