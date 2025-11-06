#include <iostream>

using namespace std;

int main() {

	int num;
	cout << "숫자를 입력하세요: ";
	cin >> num;

	switch (num % 2) {
	case 0:
		cout << "짝수입니다" << endl;
		break;
	default:
		cout << "홀수입니다" << endl;
	}

	int operation_num;
	cout << "다음 연산을 입력 하세요 1)곱하기 2, 2)더하기 15, 3)나누기 2, 4)빼기 5: ";
	cin >> operation_num;

	switch (operation_num) {
	case 1:
		num *= 2;
		cout << num << "이(가) 되었습니다" << endl;
		break;
	case 2:
		num += 15;
		cout << num << "이(가) 되었습니다" << endl;
		break;
	case 3:
		num /= 2;
		cout << num << "이(가) 되었습니다" << endl;
		break;
	case 4:
		num -= 5;
		cout << num << "이(가) 되었습니다" << endl;
		break;
	default:
		cout << "이상한 숫자를 입력해서 0이 되었습니다." << endl;
	}

	return 0;
}