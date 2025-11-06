#include <iostream>
#include <io.h> //유니코드 쓸때
#include <fcntl.h> // 유니코드 쓸때
#include <iomanip>
#include <limits>;

using namespace std;

int main() {
	/*
	bool value;

	value = true;
	cout << value << endl;
	
	value = false;
	cout << value << endl;
	*/

	/*
	wchar_t message_korean[] = L"반갑다 세계야!";
	_setmode(_fileno(stdout), _O_U16TEXT);

	wcout << message_korean << endl;
	*/

	float float_value = 9.87654321f;
	double double_value = 9.87654321987654321;
	long double long_double_value = 9.87654321987654321l;

	cout << setprecision(numeric_limits<float>::digits10 + 1) << float_value << endl << endl;
	cout << setprecision(numeric_limits<double>::digits10 + 1) << double_value << endl << endl;
	cout << setprecision(numeric_limits<long double>::digits10 + 1) << long_double_value << endl << endl;
	
	return 0;
}