/*leetcode 22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]

������������left��right�ֱ��ʾʣ���������ŵĸ����������ĳ�εݹ�ʱ�������ŵĸ������������ŵĸ�����˵����ʱ���ɵ��ַ����������ŵĸ���
    ���������ŵĸ������������')('�����ķǷ����������������ֱ�ӷ��أ��������������left��right��Ϊ0����˵����ʱ���ɵ��ַ�������3������
	�ź�3�������ţ����ַ����Ϸ�����������к󷵻ء����������������������㣬����ʱleft����0������õݹ麯����ע������ĸ��£���right��
	��0������õݹ麯����ͬ��Ҫ���²���
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		generateParenthesisDFS(n, n, "", res);
		return res;
	}
	void generateParenthesisDFS(int left, int right, string out, vector<string>& res) {
		if (left > right) {
			return;
		}
		if (left == 0 && right == 0) {
			res.push_back(out);
		}
		else {
			if (left > 0) {
				generateParenthesisDFS(left - 1, right, out + '(', res);
			}
			if (right > 0) {
				generateParenthesisDFS(left, right - 1, out + ')', res);
			}
		}
	}
};

