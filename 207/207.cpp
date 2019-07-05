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
(1)�����ı��ʾ���������ͼ�м�⻷��
(2)�������ʾһ������ͼ�������ñ�����ʾ�������������˵���ɵģ�������������ʾ�ߡ�
(3)DFS �� BFS �����Խ���⡣
   BFS:�����ά���� graph ����ʾ�������ͼ��һά���� in ����ʾÿ����������(ָ����ͼ��ĳ����Ϊͼ�бߵ��յ�Ĵ���֮��)��
       ��ʼ�ȸ��������������������ͼ�������������Ҳ��ʼ���á�Ȼ�����Ƕ���һ�� queue ���������������Ϊ0�ĵ��������У�
       Ȼ��ʼ�������У��� graph ����������ӵĵ㣬ÿ����һ���½ڵ㣬������ȼ�һ�������ʱ�õ����Ϊ0����������ĩβ��
       ֱ����������������е�ֵ������ʱ���нڵ����Ȳ�Ϊ0����˵�������ڣ����� false����֮�򷵻� true��
   DFS:��Ҫ��������ͼ�������ö�ά�������������� BFS ��ͬ���ǣ�����������Ҫһ��һά���� visit ����¼����״̬��
       ����������״̬��0��ʾ��δ���ʹ���1��ʾ�Ѿ������ˣ�-1 ��ʾ�г�ͻ������˼·�ǣ��Ƚ���������ͼ��Ȼ��ӵ�һ�ſο�ʼ��
	   ����ɹ������ſΣ���ʱ����ǰ�γ̱��Ϊ�ѷ��ʣ�Ȼ����µõ��Ŀγ̵��� DFS �ݹ飬ֱ�������µĿγ��Ѿ����ʹ��ˣ�
       �򷵻� false��û�г�ͻ�Ļ����� true��Ȼ��ѱ��Ϊ�ѷ��ʵĿγ̸�Ϊδ����.
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution1 {
public:
	bool canFinishBFS(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int> > graph(numCourses, vector<int>());//����ͼ
		vector<int> in(numCourses);//���
		for (auto a : prerequisites) {
			graph[a[1]].push_back(a[0]);//��Ҫ���a[1]�ĵ�����㣬��Ҫ��ɵĿγ��������ɵ�a[1]�γ�
			++in[a[0]];//����ɵĿγ̵��յ㣬�������
		}
		queue<int> q;
		for (int i = 0; i < numCourses; i++) {
			if (in[i] == 0) {//���Ϊ0�Ŀγ̷�������У�Ҳ���޴˿γ̲���Ҫ���������γ̵Ŀγ�,Ҳ������Ϊ����ͼ��ʼ��ĵ�
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
			if (in[i] != 0) {//�ж��Ƿ�����Ȳ�Ϊ0�ĵ�
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
		if (visit[i] == -1) {//�г�ͻ
			return false;
		}
		if (visit[i] == 1) {
			return true;//���Ϊ�ѷ���
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
	cout << "������γ�����" << endl;
	cin >> a;
	vector<vector<int> > test;
	vector<int> v;
	test.clear();
	cout << "�������ά���飺" << endl;
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