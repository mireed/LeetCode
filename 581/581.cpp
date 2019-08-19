/*leetcode 581. Shortest Unsorted Continuous Subarray
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the 
whole array will be sorted in ascending order, too.
You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

��1���½�һ����ԭ����һ��һ�������飬Ȼ�����򡣴�������ʼλ�ÿ�ʼ�����������໥�Ƚϣ�����Ӧλ�����ֲ�ͬ��ʱ��ֹͣ��ͬ���ٴ�ĩβ��ʼ����Ӧλ��
    �ϱȽϣ�Ҳ��������ͬ������ʱֹͣ�������м�һ�ξ����������������������
��2:ȷ���������������ʼ�ͽ���λ�ã���������֪��������ĳ���.��һ������start����¼��ʼλ�ã�Ȼ��ʼ�������飬������ĳ�����ֱ���ǰ�������ҪС
    ��ʱ��˵����ʱ���鲻����������Ҫ����������ǰ�ƶ����Ƶ���Ӧ���ڵĵط�������һ������j����¼�ƶ�����λ�ã�Ȼ����Ҫ��Ҫ�����λ��������
	start��ֵ����start���ǳ�ʼֵ-1ʱ���϶�Ҫ���£���Ϊ���ǳ��ֵĵ�һ������ĵط������о��������ǰλ��С��startҲҪ���£���˵����ʱ��������
	���֮ǰ�ĸ�����
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findUnsortedSubarray1(vector<int>& nums) {
	vector<int> temp = nums;
	int n = nums.size();
	int i = 0;
	int j = n - 1;
	sort(temp.begin(), temp.end());
	while (i < n && nums[i] == temp[i]) {
		++i;
	}
	while (j > i && nums[j] == temp[j]) {
		--j;
	}
	return j - i + 1;
}

int findUnsortedSubarray2(vector<int>& nums) {
	int start = -1;//��¼���򲿷ֵ���ʼλ��
	int n = nums.size();
	int res = 0;
	for (int i = 1; i < n; ++i) {
		if (nums[i] < nums[i - 1]) {
			int j = i;
			while (j > 0 && nums[j] < nums[j - 1]) {
				swap(nums[j], nums[j - 1]);
				--j;
			}
			if (start == -1 || j < start) {
				start = j;
			}
			res = i - start + 1;
		}
	}
	return res;
}