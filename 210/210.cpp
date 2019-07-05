/*leetcode 210 course schedule II
   There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
which is expressed as a pair: [0,1].Given the total number of courses and a list of prerequisite pairs, 
return the ordering of courses you should take to finish all courses.
There may be multiple correct orders, you just need to return one of them. 
If it is impossible to finish all courses, return an empty array.

  Example 1:
Input: 2, [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished
course 0. So the correct course order is [0,1] .
  Example 2:
Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both
courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .

是LeetCode207的第二版，难度加大了一点，要输出选课顺序，实则是有向图的拓扑排序 Topological Sort
用BFS来做，从 queue 中每取出一个数组就将其存在结果中，最终若有向图中有环，则结果中元素的个数不等于总课程数，那我们将结果清空即可
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
	vector<vector<int> > graph(numCourses, vector<int>());
	vector<int> res;
	vector<int> in(numCourses);
	for (auto a : prerequisites) {
		graph[a[1]].push_back(a[0]);
		++in[a[0]];
	}
	queue<int> q;
	for (int i = 0; i < numCourses; i++) {
		if (in[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int t = q.front();
		res.push_back(t);
		q.pop();
		for (auto a : graph[t]) {
			--in[a];
			if (in[a] == 0) {
				q.push(a);
			}
		}
	}
	if (res.size() != numCourses) {
		res.clear();
	}
	return res;
}

int main() {
	int a, temp;
	cout << "请输入课程数：" << endl;
	cin >> a;
	vector<vector<int> > test;
	vector<int> v;
	test.clear();
	cout << "请输入二维数组：" << endl;
	for (int i = 0; i < a; i++) {
		v.clear();
		for (int j = 0; j < 2; j++) {
			cin >> temp;
			v.push_back(temp);
		}
		test.push_back(v);
	}
	vector<int> res;
	res = findOrder(a, test);
	cout << "选课顺序是：" << endl;
	for (int i = 0; i < a; i++) {
		cout << res[i] << endl;
	}
	system("pause");
	return 0;
}
