/*leetcode 134 gas station
   There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with 
an empty tank at one of the gas stations.Return the starting gas station's index if you can travel around the circuit 
once in the clockwise direction, otherwise return -1.
  Note:
If there exists a solution, it is guaranteed to be unique.
Both input arrays are non-empty and have the same length.
Each element in the input arrays is a non-negative integer.
  Example 1:
Input:
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.

Example 2:
  Input:
gas  = [2,3,4]
cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.

    首先要知道能走完整个环的前提是gas的总量要大于cost的总量，这样才会有起点的存在。假设开始设置起点start = 0, 
并从这里出发，如果当前的gas值大于cost值，就可以继续前进，此时到下一个站点，剩余的gas加上当前的gas再减去cost，
看是否大于0，若大于0，则继续前进。当到达某一站点时，若这个值小于0了，则说明从起点到这个点中间的任何一个点都不能作为起点，
则把起点设为下一个点，继续遍历。当遍历完整个环时，当前保存的起点即为所求。
ps:用cin输入时，1、windows下：输入流对象cin输入的结束符在windows下是ctrl+z，所以，按下ctrl+z，然后回车，程序就正常跳出循环了。 
               2、UNIX/Linux下：UNIX/Linux模拟流/文件结束标志为CRTL+D
 用了两个cin时，两个cin中间要用cin.clear();
                             cin.ignore();否则程序无法正常运行
*/

#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int total = 0;
	int sum = 0;
	int start = 0;
	for (int i = 0; i < gas.size(); i++) {
		total += gas[i] - cost[i];
		sum += gas[i] - cost[i];
		if (sum < 0) {
			start = i + 1;
			sum = 0;
		}
	}
	if (total < 0) {
		return -1;
	}
	else {
		return start;
	}
}

int main() {
	vector<int> gas;
	vector<int> cost;
	int t1, t2;
	cout << "请输入第一个数组：" << endl;
	while (cin >> t1) {
		gas.push_back(t1);
	}
	cin.clear();
	cin.ignore();
	cout << "请输入第二个数组：" << endl;
	while (cin >> t2) {
		cost.push_back(t2);
	}
	int res = canCompleteCircuit(gas, cost);
	cout << res << endl;
	system("pause");
	return 0;
}