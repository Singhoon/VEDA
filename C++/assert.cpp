#include <iostream>
#include <cassert>

using namespace std;

// assert는 조건이 false일때 디버깅모드에서 확인가능

void print_number(int* _pt_int) {
	assert(_pt_int != NULL);
	cout << *_pt_int << endl;
}
int main() {
	int a = 100;
	int* b = NULL;
	int* c = NULL;

	b = &a;
	print_number(b);

	print_number(c);


	return 0;
}