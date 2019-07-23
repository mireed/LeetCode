/*leetcode 326. Power of Three
Given an integer, write a function to determine if it is a power of three.

Example 1:
Input: 27
Output: true
Example 2:
Input: 0
Output: false
Example 3:
Input: 9
Output: true
Example 4:
Input: 45
Output: false
*/

#include <iostream>

using namespace std;

bool isPowerOfThree(int n) {
	while (n && n % 3 == 0) {
		n /= 3;
	}
	return n == 1;
}

int main() {
	int test;
	cin >> test;
	cout << isPowerOfThree(test) << endl;
	system("pause");
	return 0;
}