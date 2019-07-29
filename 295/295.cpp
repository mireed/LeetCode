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

ʹ�ô�С����������⣬���д�ѱ����Ұ�νϴ�����֣�С�ѱ������ν�С�����顣������������ͱ��м��Ϊ�����ˣ����ڶѵı��淽ʽ���ɴ�С��
ϣ���������������Ǵ�С��������ȡ��һ����������λ�����㡣�õ�һ��С���ɣ����Ǵ浽����������ȡ���ٴ棬�����ɴ�С��������˳�����ʵ����
��Ҫ�Ĵ�С�����˳�򡣵���Ѻ�С���е�����һ����ʱ��ȡ�����С�ѵ���Ԫ����ƽ��ֵ����С��Ԫ�ض�ʱ��ȡС����Ԫ��Ϊ��λ��
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
		max.push(num);//ÿ���Ȱ���ѹ��󶥶ѣ��Ѿ��źôӴ�С��˳�򣬶Ѷ����
		min.push(max.top());//�Ѵ󶥶��еĶѶ���ѹ����С����
		max.pop();//���ѳ�ջ
		if (max.size() < min.size()) {//��֤����Ԫ�ظ�����Զ���ڵ�����С�Ѹ���
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
	priority_queue<int, vector<int>, greater<int> > min;//��С������С��
	priority_queue<int, vector<int>, less<int> > max;//�Ӵ�С������
};
/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder* obj = new MedianFinder();
* obj->addNum(num);
* double param_2 = obj->findMedian();
*/