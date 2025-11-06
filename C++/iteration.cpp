#include <iostream>

using namespace std;

int main() {

	for (int i = 0; i < 3; i++) {
		int num; 
		cout << "숫자를 입력하세요: ";
		cin >> num;

		if (num < 0) num = 1;
		else if (num > 20) num = 20;
		
		int max;
		cout << "최대 값을 입력하세요: ";
		cin >> max;
		
		if (max <= 1 || max >= 10000) max = 10000;

		int mults;
		cout << "증가하는 배수를 입력하세요: ";

		while (1) {
			cin >> mults;
			if (mults <= 2) {
				mults = 2;
				break;
			}
			else if (mults > 30) {
				cout << "다시 입력해주세요: ";
			}
			else break;
		}

		int result = num;
		while (result <= max) {
			result *= mults;
			if (result * mults > max) break;
		}

		cout << "입력 숫자:" << num << ", " << "최대 값:" << max << ", " << "증가 배수:" << mults << ", " << "마지막 곱:" << result << endl;
		
	}

	return 0;
}