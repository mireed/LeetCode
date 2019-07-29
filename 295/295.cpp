/*leetcode 295. Find Median from Data Stream
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is 
the mean of the two middle value.For example,[2,3,4], the median is 3.   [2,3], the median is (2 + 3) / 2 = 2.5
Design a data structure that supports the following two operations:
void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.

Example:
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2

使用大小堆来解决问题，其中大堆保存右半段较大的数字，小堆保存左半段较小的数组。这样整个数组就被中间分为两段了，由于堆的保存方式是由大到小，
希望大堆里面的数据是从小到大，这样取第一个来计算中位数方便。用到一个小技巧，就是存到大堆里的数先取反再存，这样由大到小存下来的顺序就是实际上
想要的从小到大的顺序。当大堆和小堆中的数字一样多时，取出大堆小堆的首元素求平均值，当小堆元素多时，取小堆首元素为中位数
*/

#include <iostream>
#include <queue>
#include <functional>

using namespace std;

class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		max.push(num);//每次先把数压入大顶堆，已经排好从大到小的顺序，堆顶最大
		min.push(max.top());//把大顶堆中的堆顶数压入最小堆中
		max.pop();//最大堆出栈
		if (max.size() < min.size()) {//保证最大堆元素个数永远大于等于最小堆个数
			max.push(min.top());
			min.pop();
		}
	}

	double findMedian() {
		if (max.size() <= min.size()) {
			return ((double)max.top() + (double)min.top()) / 2.0;
		}
		else {
			return (double)max.top();
		}
	}
private:
	priority_queue<int, vector<int>, greater<int> > min;//从小到大，最小堆
	priority_queue<int, vector<int>, less<int> > max;//从大到小，最大堆
};
/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder* obj = new MedianFinder();
* obj->addNum(num);
* double param_2 = obj->findMedian();
*/