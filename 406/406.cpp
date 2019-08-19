/*leetcode 406. Queue Reconstruction by Height
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the
height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an 
algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example
Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

��1�����ȸ��������Ÿ��򣬰�����߸ߵ���ǰ�棬��������ͬ����ڶ�����С����ǰ�档Ȼ���½�һ���յ����飬����֮ǰ�ź�������飬Ȼ�����ÿ��Ԫ
     �صĵڶ������֣�������뵽res�����ж�Ӧ��λ��
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
		auto cmp = [](const vector<int> &a, const vector<int> &b) {
			return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
		};
		sort(people.begin(), people.end(), cmp);
		vector<vector<int>> peopleAfter;
		for (int i = 0; i < people.size(); i++) {
			if (people[i][1] == peopleAfter.size()) {
				// Heights of all previous people are greater or equal to
				// current person.
				peopleAfter.push_back(people[i]);
			}
			else {
				// Insert at correct position
				peopleAfter.insert(peopleAfter.begin() + people[i][1],
					people[i]);
			}
		}
		return peopleAfter;
	}
};