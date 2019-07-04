/*λ���㣬�����ǽ�λʱ�����ʵ�֣���λ��������ʵ��*/
#include <iostream>

using namespace std;

int getSum(int a, int b) {
	if (b == 0) {
		return a;
	}
	int sum = a ^ b;
	int carry = (a & b & 0x7fffffff) << 1;
	return getSum(sum, carry);
}

int main() {
	int a, b;
	cin >> a >> b;
	int sum = getSum(a, b);
	cout << sum << " ";
	cout << endl;
	system("pause");
	return 0;
}