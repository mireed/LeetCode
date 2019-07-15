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

�ⷨ1���ݹ��DP���⣬��DP��ԭ����Ϊ�����Ч�ʣ������ظ����㡣ά��һ����ά��̬����dp������dp[i][j]��ʾ��������(i,j)Ϊ���������·���ĳ��ȣ�
��ʼ��dp���鶼��Ϊ0�����õݹ����ʱ������ĳ��λ��(x, y), ���dp[x][y]��Ϊ0�Ļ���ֱ�ӷ���dp[x][y]���ɣ�����Ҫ�ظ����㡣��Ҫ��������ÿ��λ�ö�
Ϊ�����õݹ��������Ƚ��ҳ����ֵ������һ��λ��Ϊ�����DFS����ʱ�������ĸ�����λ�ý����жϣ��������λ�õ�ֵ������һ��λ�ã��������λ�ü���
���õݹ飬������һ�����ֵ��������ɺ󷵻ؼ���
�ⷨ2��
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