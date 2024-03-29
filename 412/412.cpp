/*leetcode 412. Fizz Buzz
  Write a program that outputs the string representation of numbers from 1 to n.
But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. 
For numbers which are multiples of both three and five output “FizzBuzz”.

Example:
n = 15,
Return:
[
"1",
"2",
"Fizz",
"4",
"Buzz",
"Fizz",
"7",
"8",
"Fizz",
"Buzz",
"11",
"Fizz",
"13",
"14",
"FizzBuzz"
]

按题意直接分情况处理
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> fizzBuzz(int n) {
	vector<string> res;
	for (int i = 1; i <= n; ++i) {
		if (i % 15 == 0) {
			res.push_back("FizzBuzz");
		}
		else if (i % 5 == 0) {
			res.push_back("Buzz");
		}
		else if (i % 3 == 0) {
			res.push_back("Fizz");
		}
		else {
			res.push_back(to_string(i));
		}
	}
	return res;
}

int main() {
	int test;
	vector<string> result;
	cout << "请输入一个数字：" << endl;
	cin >> test;
	result = fizzBuzz(test);
	for (int i = 0; i < test; ++i) {
		cout << result[i] << " " << endl;
	}
	system("pause");
	return 0;
}