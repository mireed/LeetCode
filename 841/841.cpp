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

����ͼ�ı����������rooms������һ���ڽ�����ֱ�ӱ����ͺ�
��1���� BFS ��������ʹ��һ�� HashSet ����¼���ʹ��ķ��䣬�Ȱ�0�Ž�ȥ��Ȼ��ʹ�� queue ������������ͬ����0���롣֮����е��͵� BFS ������
ȡ�����׵ķ��䣬Ȼ��������е�����Կ�ף�����Կ�׶�Ӧ�ķ����Ѿ��������ˣ�ֱ������������ͽ�Կ�׼��� HashSet����ʱ�� HashSet �е�Կ������
�����ڷ��������ˣ�ֱ�ӷ��� true����Ϊ���ʾ���з����Ѿ����ʹ��ˣ�����ͽ�Կ�׼�����м��������������������󣬾Ϳ� HashSet �е�Կ������
��ͷ���������ȼ���
��2���ݹ����,ʹ�� HashSet ����¼���ʹ��ķ��䣬�ݹ麯������Ҫ������ǰ�ķ��䣬���� HashSet�����Ƚ���ǰ������� HashSet��Ȼ������˷�����
������Կ�ף�������Ӧ�ķ���û�з��ʹ�������õݹ麯��
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