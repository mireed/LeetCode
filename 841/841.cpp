/*leetcode 841. Keys and Rooms
There are N rooms and you start in room 0.  Each room has a distinct number in 0, 1, 2, ..., N-1, and each room may have some keys 
to access the next room.Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in
[0, 1, ..., N-1] where N = rooms.length.  A key rooms[i][j] = v opens the room with number v.
Initially, all the rooms start locked (except for room 0).You can walk back and forth between rooms freely.
Return true if and only if you can enter every room.

Example 1:
Input: [[1],[2],[3],[]]
Output: true
Explanation:
We start in room 0, and pick up key 1.
We then go to room 1, and pick up key 2.
We then go to room 2, and pick up key 3.
We then go to room 3.  Since we were able to go to every room, we return true.
Example 2:
Input: [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can't enter the room with number 2.

Note:
1 <= rooms.length <= 1000
0 <= rooms[i].length <= 1000
The number of keys in all rooms combined is at most 3000.

有向图的遍历，输入的rooms数组是一个邻接链表，直接遍历就好
法1：用 BFS 来遍历。使用一个 HashSet 来记录访问过的房间，先把0放进去，然后使用 queue 来辅助遍历，同样将0放入。之后进行典型的 BFS 遍历，
取出队首的房间，然后遍历其中的所有钥匙，若该钥匙对应的房间已经遍历过了，直接跳过，否则就将钥匙加入 HashSet。此时若 HashSet 中的钥匙数已
经等于房间总数了，直接返回 true，因为这表示所有房间已经访问过了，否则就将钥匙加入队列继续遍历。最后遍历结束后，就看 HashSet 中的钥匙数是
否和房间总数相等即可
法2：递归遍历,使用 HashSet 来记录访问过的房间，递归函数还需要传进当前的房间，还有 HashSet，首先将当前房间加入 HashSet，然后遍历此房间中
的所有钥匙，如果其对应的房间没有访问过，则调用递归函数
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

bool canVisitAllRooms1(vector<vector<int>>& rooms) {
	unordered_set<int> s{ {0} };
	queue<int> q{ {0} };
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int key : rooms[t]) {
			if (s.count(key)) {
				continue;
			}
			s.insert(key);
			if (s.size() == rooms.size()) {
				return true;
			}
			q.push(key);
		}
	}
	return s.size() == rooms.size();
}

bool canVisitAllRooms2(vector<vector<int>>& rooms) {
	unordered_set<int> s;
	helper(rooms, 0, s);
	return s.size() == rooms.size();
}
void helper(vector<vector<int>>& rooms, int cur, unordered_set<int>& s) {
	s.insert(cur);
	for (int key : rooms[cur]) {
		if (!s.count(key)) {
			helper(rooms, key, s);
		}
	}
}

int main() {
	vector<int> temp;
	vector<vector<int>> test;
	int s;
	bool flag = true;
	while (flag) {
		do {
			cin >> s;
			if (!cin) {
				flag = false;
				break;
			}
			temp.push_back(s);
		} while (cin.get() != '\n');
		if (flag) {
			test.push_back(temp);
			temp.clear();
		}
	}
	cout << canVisitAllRooms1(test) << canVisitAllRooms2(test) << endl;
	system("pause");
	return 0;
}