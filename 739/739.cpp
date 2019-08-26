/*leetcode 739. Daily Temperatures
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. 
If there is no future day for which this is possible, put 0 instead.For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output 
should be [1, 1, 4, 2, 1, 1, 0, 0].
Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].

暴力搜索(leetcode上运行超时）
使用递减栈来做，遍历数组，如果栈不空，且当前数字大于栈顶元素，那么如果直接入栈的话就不是递减栈了，所以取出栈顶元素，那么由于当前数字大于栈顶元素的数字，而且一定是
第一个大于栈顶元素的数，那么直接求出下标差就是二者的距离了，然后继续看新的栈顶元素，直到当前数字小于等于栈顶元素停止，然后将数字入栈，这样就可以一直保持递减栈，且
每个数字和第一个大于它的数的距离也可以算出来了
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures1(vector<int>& T) {
	vector<int> res;
	int flag = 0;
	int dif;
	for (int i = 0; i < T.size(); ++i) {
		flag = 0;
		for (int j = i + 1; j < T.size(); ++j) {
			if (T[j] > T[i]) {
				dif = j - i;
				res.push_back(dif);
				flag = 1;
				break;
			}
		}
	if (flag == 0) {
		res.push_back(0);
		}
	}
	return res;
}

vector<int> dailyTemperatures2(vector<int>& T) {
	int n = T.size();
	vector<int> res(n, 0);
	stack<int> st;
	for (int i = 0; i < n; ++i) {
		while (!st.empty() && T[i] > T[st.top()]) {
			auto t = st.top();
			st.pop();
			res[t] = i - t;
		}
		st.push(i);
	}
	return res;
}

int main() {
	vector<int> test, result;
	int temp;
	while (cin >> temp) {
		test.push_back(temp);
	}
	result = dailyTemperatures2(test);
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}
	system("pause");
	return 0;
}