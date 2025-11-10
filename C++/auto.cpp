#include <iostream>
#include <typeinfo>
using namespace std;

double func1() { return 1.1; }
int& func2() { static int i = 100; }

auto main() -> int {
	auto a = 1;
	auto b = 1.0;
	auto c = a + b;
	auto d = { b, c };

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;

	decltype(func1()) f1;
	int k;
	decltype(func2()) f2 = k; // 레퍼런스타입은 무조건 초기화 해야 한다


	return 0;
}