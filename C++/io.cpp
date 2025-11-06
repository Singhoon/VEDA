#include <iostream>
// endl은 개행
// namespace는 변수나 함수가 속해있는 소속을 지정
using namespace std;

int main() {
	float i, j;
	//std::cout << "Enter num_1: ";
	//std::cin >> i;
	cout << "Enter num_1: ";
	cin >> i;
	//std::cout << "Enter num_2: ";
	//std::cin >> j;
	cout << "Enter num_2: ";
	cin >> j;

	//std::cout << "num_1 + num_2 = " << i + j << std::endl;
	cout << "num_1 + num_2 = " << i + j << std::endl;

	return 0;
}