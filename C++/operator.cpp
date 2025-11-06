#include <iostream>
using namespace std;
// cout 시에 cout << hex << 변수 ; 이렇게 16진수로 표현 가능. C에서는 %x.
int main() {

	string string_value("Hello, ");
	string string_value2;
	cin >> string_value2;

	cout << string_value + string_value2 << endl;

	return 0;
}