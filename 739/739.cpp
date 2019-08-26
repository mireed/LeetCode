/*leetcode 739. Daily Temperatures
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. 
If there is no future day for which this is possible, put 0 instead.For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output 
should be [1, 1, 4, 2, 1, 1, 0, 0].
Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].

��������(leetcode�����г�ʱ��
ʹ�õݼ�ջ�������������飬���ջ���գ��ҵ�ǰ���ִ���ջ��Ԫ�أ���ô���ֱ����ջ�Ļ��Ͳ��ǵݼ�ջ�ˣ�����ȡ��ջ��Ԫ�أ���ô���ڵ�ǰ���ִ���ջ��Ԫ�ص����֣�����һ����
��һ������ջ��Ԫ�ص�������ôֱ������±����Ƕ��ߵľ����ˣ�Ȼ��������µ�ջ��Ԫ�أ�ֱ����ǰ����С�ڵ���ջ��Ԫ��ֹͣ��Ȼ��������ջ�������Ϳ���һֱ���ֵݼ�ջ����
ÿ�����ֺ͵�һ�������������ľ���Ҳ�����������
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