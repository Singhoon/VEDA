#include <iostream>
#include <limits>

using namespace std;

int main() {

	unsigned int num, mults;

	cout << "숫자를 입력하세요: ";
	cin >> num;

	cout << "곱하는 숫자를 입력하세요: ";
	cin >> mults;

	try {

		unsigned int result = num * mults;
		if ((num * mults) > INT_MAX) {
			throw INT_MAX;
		}
		cout << num << " * " << mults << " = " << num * mults << " 입니다." << endl;

	}
	catch (unsigned int result) {
		cout << endl;
		cout << "결과값이 정수형 int의 최대(소) 값을 벗어 납니다." << endl;
	}
	
	return 0;
}