/*leetcode 771. Jewels and Stones
  You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  
Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.
The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so
"a" is considered a different type of stone from "A".

  Example 1:
Input: J = "aA", S = "aAAbbbb"
Output: 3
  Example 2:
Input: J = "z", S = "ZZ"
Output: 0

  Note:
S and J will consist of letters and have length at most 50.The characters in J are distinct.

���⣬ֱ���ñ����������߹�ϣset
*/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

//��������
class Solution1 {
public:
	int numJewelsInStones1(string J, string S) {
		int res = 0;
		for (char it1 : S) {
			for (char it2 : J) {
				if (it1 == it2) {
					res++;
					break;
				}
			}
		}
		return res;
	}
};

//��ϣ��
class Solution2 {
public:
	int numJewelsInStones2(string J, string S) {
		int res = 0;
		unordered_set<char> s;
		for (char it1 : J) {
			s.insert(it1);
		}
		for (char it2 : S) {
			if (s.count(it2)) {
				res++;
			}
		}
		return res;
	}
};

int main() {
	int result1, result2;
	string J, S;
	cout << "�������鱦�ַ�����" << endl;
	getline(cin, J);
	cout << "������ʯͷ�ַ�����" << endl;
	getline(cin, S);
	Solution1 s1;
	Solution2 s2;
	result1 = s1.numJewelsInStones1(J, S);
	result2 = s2.numJewelsInStones2(J, S);
	cout << result1 << " ";
	cout << result2 << endl;
	system("pause");
	return 0;
}