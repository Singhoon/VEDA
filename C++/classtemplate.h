#pragma once
#include <iostream>

using namespace std;

template <typename T1, typename T2>
class data_package {
public:
	data_package(T1 first, T2 second) : first(first), second(second) {}
	void print_out_element() {
		cout << "첫 번째 요소 " << first << ", 두 번째 요소 " << second << endl;
	}
private:
	T1 first;
	T2 second;
};