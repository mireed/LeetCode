/*leetcode 198. House Robber
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only 
constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically 
contact the police if two adjacent houses were broken into on the same night.Given a list of non-negative integers representing the
amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:
Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

��1����̬�滮Dynamic Programming��ά��һ��һλ����dp������dp[i]��ʾ��iλ��ʱ�����������γɵ����ͣ���һ������������һ�£�����˵numsΪ
{3, 2, 1, 5}������dp[0]=3������3��2��������������һ�����ӵ�3����ǰ���ӵ�2����������dp[1]=3�����ڲ��������ڵģ���������ǰ���һ����dpֵ
���ϵ�ǰ�ķ���ֵ���͵�ǰ�����ǰ��һ��dpֵ�Ƚϣ�ȡ�ϴ�ֵ������ǰdpֵ���������ǿ��Եõ�״̬ת�Ʒ���dp[i] = max(num[i] + dp[i - 2],dp[i - 1])
, �ɴ˿�����Ҫ��ʼ��dp[0]��dp[1]������dp[0]��Ϊnum[0]��dp[1]��ʱӦ��Ϊmax(num[0], num[1])

��2������˼�뻹����DP���ֱ�ά����������robEven��robOdd������˼�壬robEven����Ҫ��ż��λ�õķ��ӣ�robOdd����Ҫ������λ�õķ��ӡ������ڱ�������
����ʱ�������ż��λ�ã���ôrobEven��Ҫ���ϵ�ǰ���֣�Ȼ���robOdd�Ƚϣ�ȡ�ϴ��������robEven��robEven��ɵ�ֵ������ֻ��ż��λ�õ����֣�ֻ��
��ǰҪ��ż��λ�ö��ѡ�ͬ��������λ��ʱ��robOdd���ϵ�ǰ���ֺ�robEven�Ƚϣ�ȡ�ϴ�ֵ������robOdd�����ְ���ż�ֱ������µķ��������Ա�֤������
�͵����ֲ����ڣ�����������robEven��robOdd��ȡ�ϴ�ֵ����
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//��1
int rob1(vector<int>& nums) {
	if (nums.size() <= 1) {
		if (nums.empty()) {
			return 0;
		}
		else {
			return nums[0];
		}
	}
	vector<int> dp{ nums[0], max(nums[0], nums[1]) };
	for (int i = 2; i < nums.size(); ++i) {
		dp.push_back(max(dp[i - 1], dp[i - 2] + nums[i]));
	}
	return dp.back();
}

//��2
int rob2(vector<int>& nums) {
	int robEven = 0, robOdd = 0, n = nums.size();
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			robEven = max(robEven + nums[i], robOdd);
		}
		else {
			robOdd = max(robEven + nums[i], robEven);
		}
	}
	return max(robOdd, robEven);
}

int main() {
	int temp;
	vector<int> test;
	while (cin >> temp) {
		test.push_back(temp);
	}
	cout << rob1(test) << endl;
	cout << rob2(test) << endl;
	system("pause");
	return 0;
}