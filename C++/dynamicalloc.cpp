#include <iostream>
#include <string>
using namespace std;
// new, delete로 malloc, free 대체
// null 할당은 NULL대신 nullptr로 대체
int main() {

	/*
	int* pt_int_value = new int;

	*pt_int_value = 100;
	cout << *pt_int_value << endl;

	delete pt_int_value;
	*/

	/*
	int* pt_int_array_value = new int[5];

	for (int i = 0; i < 5; i++) {
		pt_int_array_value[i] = i;
	}

	for (int i = 0; i < 5; i++) {
		cout << pt_int_array_value[i] << endl;
	}

	delete[] pt_int_array_value;
	*/

	// 5명의 주소록을 관리하기 위한 주소록 이름과 주소 각각 넣기. ...이 입력되면 빠져나오기. 그 다음에 이름과 주소를 한번에 주욱 출력. 메모리 해제까지. 먼저 사람 수 입력 시작
	/*
	int num;
	cin >> num;

	string* name = new string[num];
	string* address = new string[num];

	for (int i = 0; i < num; i++) {
		cin >> name[i] >> address[i];
	}

	for (int i = 0; i < num; i++) {
		cout << name[i] << ' ' << address[i] << endl;
	}
	delete[] name;
	delete[] address;

	// 메모리 해제해도 nullptr로 포인터변수 초기화 권장. 이후에 해당 메모리 참조 못하게 하는 것 권장
	name = nullptr;
	address = nullptr; 
	*/

	int size;
	cout << "배열의 전체 크기를 입력하세요: ";
	cin >> size;

	long long* fib = new long long[size];
	if (size == 1) {
		*fib = 1;
	}
	else if (size == 2) {
		*fib = 1;
		*(fib + 1) = 1;
	}
	else {
		*fib = 1;
		*(fib + 1) = 1;
		for (int i = 2; i < size; i++) {
			*(fib + i) = *(fib+(i-1)) + *(fib+(i-2));
		}
	}
	int start;
	cout << "몇 번째 숫자마다 출력할까요?: ";
	cin >> start;

	if (start <= 0 || start > size) {
		cout << "출력이 안됩니다." << endl;
	}
	else {
		int pos = start - 1;
		while (pos <= size - 1) {
			cout << *(fib + pos) <<  " ";
			pos += start;
		}
	}
	delete[] fib;
	return 0;
}