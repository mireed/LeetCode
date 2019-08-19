/*leetcode 581. Shortest Unsorted Continuous Subarray
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the 
whole array will be sorted in ascending order, too.
You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

法1：新建一个跟原数组一摸一样的数组，然后排序。从数组起始位置开始，两个数组相互比较，当对应位置数字不同的时候停止，同理再从末尾开始，对应位置
    上比较，也是遇到不同的数字时停止，这样中间一段就是最短无序连续子数组了
法2:确定无序子数组的起始和结束位置，这样就能知道子数组的长度.用一个变量start来记录起始位置，然后开始遍历数组，当发现某个数字比其前面的数字要小
    的时候，说明此时数组不再有序，所以要将此数字向前移动，移到其应该在的地方，用另一个变量j来记录移动到的位置，然后考虑要不要用这个位置来更新
	start的值，当start还是初始值-1时，肯定要更新，因为这是出现的第一个无序的地方，还有就是如果当前位置小于start也要更新，这说明此时的无序数
	组比之前的更长了
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
	int start = -1;//记录无序部分的起始位置
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