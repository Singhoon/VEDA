#include <iostream>
#include <cstdlib>


using namespace std;
int* ptr_int = nullptr;

void myterminate() {
	cout << "myterminate called" << endl;

	delete[] ptr_int;
	ptr_int = nullptr;

	exit(-1);
}
int main() {
	set_terminate(myterminate);

	int num;
	cout << "숫자를 입력하세요: ";
	cin >> num;

	ptr_int = new int[num];

	throw 1;

	delete[] ptr_int;
	ptr_int = nullptr;
	cout << "올바르게 해제되었음." << endl;

	return 0;
}