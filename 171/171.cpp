/*leetcode 171. Excel Sheet Column Number
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...
Example 1:
Input: "A"
Output: 1
Example 2:
Input: "AB"
Output: 28
Example 3:
Input: "ZY"
Output: 701

26进制转换为10进制的问题，如ZY = 26 * 26^1 + 25 * 26^0 = 701
*/

#include <iostream>
#include <string>

using namespace std;

int titleToNumber(string s) {
	int temp = 1, res = 0;
	for (int i = s.size(); i > 0; --i) {
		res += (s[i - 1] - 'A' + 1) * temp;
		temp *= 26;
	}
	return res;
}

int main() {
	string test;
	getline(cin, test);
	cout << titleToNumber(test) << endl;
	system("pause");
	return 0;
}