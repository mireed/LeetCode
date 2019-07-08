/*leetcode 166. Fraction to Recurring Decimal
  Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.

  Example 1:
Input: numerator = 1, denominator = 2
Output: "0.5"
  Example 2:
Input: numerator = 2, denominator = 1
Output: "2"
  Example 3:
Input: numerator = 2, denominator = 3
Output: "0.(6)"

    可以写成分数的都是有理数，而有理数要么是有限的，要么是无限循环小数，无限不循环的叫无理数，例如圆周率pi或自然数e等，
对于正负情况，处理方式是按正数处理，符号最后再判断，把除数和被除数取绝对值，但由于整型数INT的取值范围是-2147483648～2147483647，
而对-2147483648取绝对值就会超出范围，先转为long long型再取绝对值。对于找循环，采用哈希表来存数每个小数位上的数字。要算出小数每一位，
采取的方法是每次把余数乘10，再除以除数，得到的商即为小数的下一位数字。等到新算出来的数字在之前出现过，则在循环开始出加左括号，结束处加右括号。
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		int s1 = numerator > 0 ? 1 : -1;
		int s2 = denominator > 0 ? 1 : -1;
		long long num = abs((long long)numerator);
		long long den = abs((long long)denominator);
		long long out = num / den;
		long long rem = num % den;
		unordered_map<long long, int> m;
		string res = to_string(out);
		if (s1 * s2 == -1 && (num > 0 || rem > 0)) {
			res = "-" + res;
		}
		if (rem == 0) {
			return res;
		}
		res += ".";
		string s = "";
		int pos = 0;
		while (rem != 0) {
			if (m.find(rem) != m.end()) {//find通过给定主键查找元素,没找到：返回unordered_map::end,这儿不等于end说明找到了，也就是之前出现过
				s.insert(m[rem], "(");//在m[ren]的位置前插入左括号
				s += ")";
				return res + s;
			}
			m[rem] = pos;
			s += to_string(rem * 10 / den);
			rem = (rem * 10) % den;
			pos++;
		}
		return res + s;
	}
};

int main() {
	int a, b;
	cout << "请输入分母和分子： " << endl;
	cin >> a >> b;
	Solution t;
	string result = t.fractionToDecimal(a, b);
	cout << result << endl;
	system("pause");
	return 0;
}