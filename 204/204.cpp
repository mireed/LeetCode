/*leetcode 204. Count Primes
Count the number of prime numbers less than a non-negative number, n.

Example:
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

������˹����ɸ��Sieve of Eratosthenes����2��ʼ����������n�����ҵ���һ������2��Ȼ�������еı���ȫ����ǳ�����Ȼ����һ������3�����������
������һ�����ƣ�ֱ������n����ʱ������δ����ǵ����־�����������Ҫһ��n-1���ȵ�bool����������¼ÿ�������Ƿ񱻱�ǣ�����Ϊn-1��ԭ������Ŀ˵��С
��n��������������������n��
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