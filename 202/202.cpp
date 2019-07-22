/*leetcode 202. Happy Number
Write an algorithm to determine if a number is "happy".A happy number is a number defined by the following process: Starting with 
any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1
(where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are
happy numbers.

Example:
Input: 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

¹þÏ£set
*/

#include <iostream>
#include <unordered_set>

using namespace std;

bool isHappy(int n) {
	unordered_set<int> s;
	int sum = 0;
	while (n != 1) {
		while (n) {
			sum += (n % 10) * (n % 10);
			n = n / 10;
		}
		n = sum;
		if (s.count(n)) {
			break;
		}
		s.insert(n);
	}
	return n == 1;
}

int main() {
	int test;
	cin >> test;
	cout << isHappy(test) << endl;
	system("pause");
	return 0;
}