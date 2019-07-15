/*leetcode 122. Best Time to Buy and Sell Stock II
Say you have an array for which the ith element is the price of a given stock on day i.Design an algorithm to find the maximum 
profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:
Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:
Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
engaging multiple transactions at the same time. You must sell before buying again.
Example 3:
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.


*/

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
	int res = 0;
	for (int i = 0; i < (int)prices.size() - 1; ++i) {//本地IDE上可不用转换成int型，OJ上要用强制转换，因为prices.size()返回的是size_type
		                                              //型的，这是一种unsigned类型，也就是无符号类型，所以在直接对其做减法是不行的，因为负
		                                             //数对其来说不合法，所以我们可以先强制将其转为整型，再做减法
		if (prices[i + 1] > prices[i]) {
			res += prices[i + 1] - prices[i];
		}
	}
	return res;
}

int main() {
	vector<int> test;
	int temp;
	while (cin >> temp) {
		test.push_back(temp);
	}
	cout << maxProfit(test) << endl;
	system("pause");
	return 0;
}