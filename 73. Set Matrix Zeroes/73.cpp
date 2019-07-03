/*
��˵������CareerCup�ϵ�ԭ�⣬�һ�û��ˢCareerCup�����Բ�֪��������������Ҳ�����ѣ���Ȼ��Ҳ�ǿ������ϵĽⷨ����д�ģ�
�����´�������������������������˵�Ŀռ临�Ӷ�ΪO(mn)�Ľⷨ�Բ��ö�˵��ֱ���½�һ����matrix�ȴ�С�ľ���
Ȼ��һ��һ�е�ɨ��ֻҪ��0���ͽ��½��ľ���Ķ�Ӧ��ȫ��0����ɨ����ɨ�У�Ȼ��Ѹ�����ľ��󸳸�matrix���ɣ�����㷨�Ŀռ临�Ӷ�̫�ߡ�
�����Ż���O(m+n)�ķ����ǣ���һ������Ϊm��һά�����¼�������Ƿ���0����һ������Ϊn��һά�����¼�������Ƿ���0��
���ֱ�Ӹ���matrix���鼴�ɡ�������Ҫ������O(1)�Ŀռ䣬��ô���ǾͲ����½����飬���ǿ��Ǿ���ԭ����ĵ�һ�е�һ������¼���и����Ƿ���0.

- ��ɨ���һ�е�һ�У������0���򽫸��Ե�flag����Ϊtrue
- Ȼ��ɨ���ȥ��һ�е�һ�е��������飬�����0���򽫶�Ӧ�ĵ�һ�к͵�һ�е����ָ�0
- �ٴα�����ȥ��һ�е�һ�е��������飬�����Ӧ�ĵ�һ�к͵�һ�е�������һ��Ϊ0���򽫵�ǰֵ��0
- �����ݵ�һ�е�һ�е�flag�����µ�һ�е�һ��
*/

#include <iostream>
#include <vector>

using namespace std;


	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return;
		}
		int m = matrix.size();
		int n = matrix[0].size();
		bool colflag = false;
		bool rowflag = false;
		for (int i = 0; i < m; i++) {
			if (matrix[i][0] == 0) {
				colflag = true;
			}
		}
		for (int j = 0; j < n; j++) {
			if (matrix[0][j] == 0) {
				rowflag = true;
			}
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
			}
		}
		if (colflag) {
			for (int i = 0; i < m; i++) {
				matrix[i][0] = 0;
			}
		}
		if (rowflag) {
			for (int j = 0; j < n; j++) {
				matrix[0][j] = 0;
			}
		}
	}

	int main() {
		vector <vector<int> > test;
		vector <int> v;
		int m, n, temp;
		cout << "��������������" << endl;
		cin >> m >> n;
		test.clear();
		cout << "�������ά���飺" << endl;
		for (int i = 0; i < m; i++) {
			v.clear();
			for (int j = 0; j < n; j++) {
				cin >> temp;
				v.push_back(temp);
			}
			test.push_back(v);
		}
		setZeroes(test);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << test[i][j] << " ";
			}
			cout << endl;
		}
		system("pause");
		return 0;
	}