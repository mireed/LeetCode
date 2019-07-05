/*leetcode 207 course schedule
  There are a total of n courses you have to take, labeled from 0 to n-1.Some courses may have prerequisites, 
for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
  Example 1:
Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
  Example 2:
Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
(1)这道题的本质就是在有向图中检测环。
(2)如何来表示一个有向图，可以用边来表示，边是由两个端点组成的，用两个点来表示边。
(3)DFS 和 BFS 都可以解此题。
   BFS:定义二维数组 graph 来表示这个有向图，一维数组 in 来表示每个顶点的入度(指有向图中某点作为图中边的终点的次数之和)。
       开始先根据输入来建立这个有向图，并将入度数组也初始化好。然后我们定义一个 queue 变量，将所有入度为0的点放入队列中，
       然后开始遍历队列，从 graph 里遍历其连接的点，每到达一个新节点，将其入度减一，如果此时该点入度为0，则放入队列末尾。
       直到遍历完队列中所有的值，若此时还有节点的入度不为0，则说明环存在，返回 false，反之则返回 true。
   DFS:需要建立有向图，还是用二维数组来建立，和 BFS 不同的是，我们现在需要一个一维数组 visit 来记录访问状态，
       这里有三种状态，0表示还未访问过，1表示已经访问了，-1 表示有冲突。大体思路是，先建立好有向图，然后从第一门课开始，
	   找其可构成哪门课，暂时将当前课程标记为已访问，然后对新得到的课程调用 DFS 递归，直到出现新的课程已经访问过了，
       则返回 false，没有冲突的话返回 true，然后把标记为已访问的课程改为未访问.
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution1 {
public:
	bool canFinishBFS(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int> > graph(numCourses, vector<int>());//有向图
		vector<int> in(numCourses);//入度
		for (auto a : prerequisites) {
			graph[a[1]].push_back(a[0]);//先要完成a[1]的当做起点，先要完成的课程流向后完成的a[1]课程
			++in[a[0]];//后完成的课程当终点，算其入度
		}
		queue<int> q;
		for (int i = 0; i < numCourses; i++) {
			if (in[i] == 0) {//入度为0的课程放入队列中，也即修此课程不需要先修其他课程的课程,也即可作为有向图起始点的点
				q.push(in[i]);
			}
		}
		while (!q.empty()) {
			int t = q.front();
			q.pop();
			for (auto a : graph[t]) {
				--in[a];
				if (in[a] == 0) {
					q.push(a);
				}
			}
		}
		for (int i = 0; i < numCourses; i++) {
			if (in[i] != 0) {//判断是否还有入度不为0的点
				return false;
			}
		}
		return true;
	}
};

class Solution2 {
public:
	bool canFinishDFS(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int> > graph(numCourses, vector<int>());
		vector<int> visited(numCourses);
		for (auto a : prerequisites) {
			graph[a[1]].push_back(a[0]);
		}
		for (int i = 0; i < numCourses; i++) {
			if (!canFinishDFScore(graph, visited, i)) {
				return false;
			}
		}
		return true;
	}
	bool canFinishDFScore(vector<vector<int>>& graph, vector<int>& visit, int i) {
		if (visit[i] == -1) {//有冲突
			return false;
		}
		if (visit[i] == 1) {
			return true;//标记为已访问
		}
		visit[i] = -1;
		for (auto a : graph[i]) {
			if (!canFinishDFScore(graph, visit, a)) {
				return false;
			}
		}
		visit[i] = 1;
		return true;
	}

};

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
	Solution1 s1;
	Solution2 s2;
	bool flag1 = s1.canFinishBFS(a, test);
	bool flag2 = s2.canFinishDFS(a, test);
	cout << flag1 << " ";
	cout << flag2 << " ";
	cout << endl;
	system("pause");
	return 0;
}