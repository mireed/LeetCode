/*LeetCode 329. Longest Increasing Path in a Matrix
  Given an integer matrix, find the length of the longest increasing path.
From each cell, you can either move to four directions: left, right, up or down. 
You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

  Example 1:
Input: nums =
[
[9,9,4],
[6,6,8],
[2,1,1]
]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
  Example 2:
Input: nums =
[
[3,4,5],
[3,2,6],
[2,2,1]
]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

解法1：递归和DP来解，用DP的原因是为了提高效率，避免重复运算。维护一个二维动态数组dp，其中dp[i][j]表示数组中以(i,j)为起点的最长递增路径的长度，
初始将dp数组都赋为0，当用递归调用时，遇到某个位置(x, y), 如果dp[x][y]不为0的话，直接返回dp[x][y]即可，不需要重复计算。需要以数组中每个位置都
为起点调用递归来做，比较找出最大值。在以一个位置为起点用DFS搜索时，对其四个相邻位置进行判断，如果相邻位置的值大于上一个位置，则对相邻位置继续
调用递归，并更新一个最大值，搜素完成后返回即可
解法2：
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
	int longestIncreasingPath1(vector<vector<int>>& matrix) {

	}
};

class Solution2 {
public:
	int longestIncreasingPath2(vector<vector<int>>& matrix) {

	}
};