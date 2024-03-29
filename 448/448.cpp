/*leetcode 448. Find All Numbers Disappeared in an Array
  Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:
Input:
[4,3,2,7,8,2,3,1]
Output:
[5,6]

法1：将nums[i]置换到其对应的位置nums[nums[i]-1]上去，比如对于没有缺失项的正确的顺序应该是[1, 2, 3, 4, 5, 6, 7, 8]，而我们现在却是
     [4,3,2,7,8,2,3,1]，我们需要把数字移动到正确的位置上去，比如第一个4就应该和7先交换个位置，以此类推，最后得到的顺序应该是
	 [1, 2, 3, 4, 3, 2, 7, 8]，我们最后在对应位置检验，如果nums[i]和i+1不等，那么我们将i+1存入结果res中即可
法2：对于每个数字nums[i]，如果其对应的nums[nums[i] - 1]是正数，我们就赋值为其相反数，如果已经是负数了，就不变了，那么最后我们只要把
     留下的整数对应的位置加入结果res中即可
*/

#include <iostream>
#include <vector>

using namespace std;

//法1
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

//法2
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
	cout << "请输入数组：" << endl;
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
