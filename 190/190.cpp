/*leetcode 190. Reverse Bits
Reverse bits of a given 32 bits unsigned integer.

Example 1:
Input: 00000010100101000001111010011100
Output: 00111001011110000010100101000000
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 
43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.
Example 2:
Input: 11111111111111111111111111111101
Output: 10111111111111111111111111111111
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer
4294967293, so return 3221225471 which its binary representation is 10101111110010110010011101101001.

把要翻转的数从右向左一位位的取出来，如果取出来的是1，将结果res左移一位并且加上1；如果取出来的是0，将结果res左移一位，然后将n右移一位即可
*/

#include <iostream>

using namespace std;

uint32_t reverseBits(uint32_t n) {
	uint32_t res = 0;
	for (int i = 0; i < 31; ++i) {
		if (n & 1 == 1) {
			res = (res << 1) + 1;
		}
		else {
			res << 1;
		}
		n = n >> 1;
	}
	return res;
}

int main() {
	uint32_t test;
	cin >> test;
	cout << reverseBits(test) << endl;
	system("pause");
	return 0;
}