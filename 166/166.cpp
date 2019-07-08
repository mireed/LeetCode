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

    ����д�ɷ����Ķ�������������������Ҫô�����޵ģ�Ҫô������ѭ��С�������޲�ѭ���Ľ�������������Բ����pi����Ȼ��e�ȣ�
�����������������ʽ�ǰ�������������������жϣ��ѳ����ͱ�����ȡ����ֵ��������������INT��ȡֵ��Χ��-2147483648��2147483647��
����-2147483648ȡ����ֵ�ͻᳬ����Χ����תΪlong long����ȡ����ֵ��������ѭ�������ù�ϣ��������ÿ��С��λ�ϵ����֡�Ҫ���С��ÿһλ��
��ȡ�ķ�����ÿ�ΰ�������10���ٳ��Գ������õ����̼�ΪС������һλ���֡��ȵ����������������֮ǰ���ֹ�������ѭ����ʼ���������ţ��������������š�
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
			if (m.find(rem) != m.end()) {//findͨ��������������Ԫ��,û�ҵ�������unordered_map::end,���������end˵���ҵ��ˣ�Ҳ����֮ǰ���ֹ�
				s.insert(m[rem], "(");//��m[ren]��λ��ǰ����������
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
	cout << "�������ĸ�ͷ��ӣ� " << endl;
	cin >> a >> b;
	Solution t;
	string result = t.fractionToDecimal(a, b);
	cout << result << endl;
	system("pause");
	return 0;
}