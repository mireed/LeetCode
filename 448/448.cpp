/*leetcode 448. Find All Numbers Disappeared in an Array
  Given an array of integers where 1 �� a[i] �� n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:
Input:
[4,3,2,7,8,2,3,1]
Output:
[5,6]

��1����nums[i]�û������Ӧ��λ��nums[nums[i]-1]��ȥ���������û��ȱʧ�����ȷ��˳��Ӧ����[1, 2, 3, 4, 5, 6, 7, 8]������������ȴ��
     [4,3,2,7,8,2,3,1]��������Ҫ�������ƶ�����ȷ��λ����ȥ�������һ��4��Ӧ�ú�7�Ƚ�����λ�ã��Դ����ƣ����õ���˳��Ӧ����
	 [1, 2, 3, 4, 3, 2, 7, 8]����������ڶ�Ӧλ�ü��飬���nums[i]��i+1���ȣ���ô���ǽ�i+1������res�м���
��2������ÿ������nums[i]��������Ӧ��nums[nums[i] - 1]�����������Ǿ͸�ֵΪ���෴��������Ѿ��Ǹ����ˣ��Ͳ����ˣ���ô�������ֻҪ��
     ���µ�������Ӧ��λ�ü�����res�м���
*/

#include <iostream>
#include <vector>

using namespace std;

//��1
vector<int> findDisappearedNumbers1(vector<int>& nums) {
	vector<int> res;
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] != nums[nums[i] - 1]) {
			swap(nums[i], nums[nums[i] - 1]);
			--i;
		}
	}
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] != i + 1) {
			res.push_back(i + 1);
		}
	}
	return res;
}

//��2
vector<int> findDisappearedNumbers2(vector<int>& nums) {
	vector<int> res;
	for (int i = 0; i < nums.size(); ++i) {
		int idx = abs(nums[i]) - 1;
		if (nums[idx] > 0) {
			nums[idx] = -nums[idx];
		}
		else {
			nums[idx] = nums[idx];
		}
	}
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] > 0) {
			res.push_back(i + 1);
		}
	}
	return res;
}

int main() {
	vector<int> test, result1, result2;
	cout << "���������飺" << endl;
	int temp;
	while (cin >> temp) {
		test.push_back(temp);
	}
	result1 = findDisappearedNumbers1(test);
	result2 = findDisappearedNumbers2(test);
	for (int i = 0; i < result1.size(); ++i) {
		cout << result1[i] << " " << endl;
	}
	for (int i = 0; i < result2.size(); ++i) {
		cout << result2[i] << " " << endl;
	}
	system("pause");
	return 0;
}
