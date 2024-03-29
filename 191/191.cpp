/*leetcode 191. Number of 1 Bits
Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).

Example 1:
Input: 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
Example 2:
Input: 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
Example 3:
Input: 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.

λ����
*/

#include <iostream>

using namespace std;

int hammingWeight(uint32_t n) {
	int res = 0;
	for (int i = 0; i < 32; ++i) {
		res += (n & 1);
		n = n >> 1;
	}
	return res;
}

int main() {
	uint32_t test;
	cin >> test;
	cout << hammingWeight(test) << endl;
	system("pause");
	return 0;
}