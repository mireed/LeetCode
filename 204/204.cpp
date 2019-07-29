/*leetcode 204. Count Primes
Count the number of prime numbers less than a non-negative number, n.

Example:
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

埃拉托斯特尼筛法Sieve of Eratosthenes，从2开始遍历到根号n，先找到第一个质数2，然后将其所有的倍数全部标记出来，然后到下一个质数3，标记其所有
倍数，一次类推，直到根号n，此时数组中未被标记的数字就是质数。需要一个n-1长度的bool型数组来记录每个数字是否被标记，长度为n-1的原因是题目说是小
于n的质数个数，并不包括n。
*/

#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n) {
	int res = 0;
	vector<bool> flag(n, true);
	for (int i = 2; i < 2; ++i) {
		if (flag[i]) {
			++res;
		}
		for (int j = 2; i * j < n; ++j) {
			flag[i * j] = false;
		}
	}
	return res;
}

int main() {
	int test;
	cin >> test;
	cout << countPrimes(test) << endl;
	system("pause");
	return 0;
}