#include <iostream>

using namespace std;


template <typename T> // template <class T>
void myswap(T& a, T& b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

int main() {

	int a = 4, b = 5;
	myswap(a, b);
	cout << a << ' ' << b << endl;

	double c = 4.1, d = 5.7;
	myswap(c, d);
	cout << c << ' ' << d << endl;

	string e = "michael", f = "thomas";
	myswap(e, f);
	cout << e << ' ' << f << endl;

	return 0;
}