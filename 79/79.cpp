/*leetcode 79. Word Search
Given a 2D board and a word, find if the word exists in the grid.The word can be constructed from letters of sequentially adjacent 
cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:
board =
[
['A','B','C','E'],
['S','F','C','S'],
['A','D','E','E']
]
Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

»ØËÝ·¨£¬DFS±éÀú
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool helpDFS(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int idex, int i, int j) {
	if (idex == word.size()) {
		return true;
	}
	int m = board.size();
	int n = board[0].size();
	if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || board[i][j] != word[idex]) {
		return false;
	}
	visited[i][j] = true;
	bool res = helpDFS(board, visited, word, idex + 1, i - 1, j) || helpDFS(board, visited, word, idex + 1, i + 1, j)
		|| helpDFS(board, visited, word, idex + 1, i, j - 1) || helpDFS(board, visited, word, idex + 1, i, j + 1);
	visited[i][j] = false;
	return res;
}

bool exist(vector<vector<char>>& board, string word) {
	if (board.empty() || board[0].empty()) {
		return false;
	}
	int m = board.size();
	int n = board[0].size();
	vector<vector<bool>> visited(m, vector<bool>(n));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (helpDFS(board, visited, word, 0, i, j)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	vector<vector<char>> test1;
	vector<char> temp1;
	string test2;
	getline(cin, test2);
	char temp2;
	bool flag = true;
	while (flag) {
		do {
			cin >> temp2;
			temp1.push_back(temp2);
			if (!cin) {
				flag = false;
				break;
			}
		} while (cin.get() != '\n');
		if (flag) {
			test1.push_back(temp1);
			temp1.clear();
		}
	}
	cout << exist(test1, test2) << endl;
	system("pause");
	return 0;
}