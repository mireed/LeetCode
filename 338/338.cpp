/*leetcode 338. Counting Bits
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary 
representation and return them as an array.

Example 1:
Input: 2
Output: [0,1,1]
Example 2:
Input: 5
Output: [0,1,1,2,1,2]

除去前两个数字0个1，从2开始，2和3，是 [21, 22) 区间的，值为1和2。而4到7属于 [22, 23) 区间的，值为 1,2,2,3，前半部分1和2和上一区间相同，
2和3是上面的基础上每个数字加1。再看8到 15，属于 [23, 24) 区间的，同样满足上述规律
0000    0
-------------
0001    1
-------------
0010    1
0011    2
-------------
0100    1
0101    2
0110    2
0111    3
-------------
1000    1
1001    2
1010    2
1011    3
1100    2
1101    3
1110    3
1111    4
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int num) {
	if (num == 0) {
		return {0};
	}
	vector<int> res{ 0, 1 };
	int i = 2, k = 2;
	while (i <= num) {
		for (i = pow(2, k - 1); i < pow(2, k); ++i) {
			if (i > num) {
				break;
			}
			int t = (pow(2, k) - pow(2, k - 1)) / 2;
			if (i < pow(2, k - 1) + t) {
				res.push_back(res[i - t]);
			}
			else {
				res.push_back(res[i - t] + 1);
			}
		}
		++k;
	}
	return res;
}

int main() {
	vector<int> result;
	int test;
	cin >> test;
	result = countBits(test);
	for(int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}
	system("pause");
	return 0;
}