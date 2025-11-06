#include <iostream>
#include <cstdlib>


using namespace std;


int sum(int a, int b, int c) {
	return a + b + c;
}

double sum(double a, double b) {
	return a + b;
}

int sum(int a, int b) {
	return a + b;
}
/*
double sum(int a, int b) {
	return (double)(a + b);
}
*/

int big(int a, int b) {
	if (a >= b) return a;
	else return b;
}

int big(int a[], int size) {
	int max = a[0];
	for (int i = 1; i < size; i++) {
		if (a[i] > max) max = a[i];
	}
	return max;
}

int main() {

	
	cout << sum(2, 5, 33) << endl;

	cout << sum(12.5, 33.6) << endl;
	
	cout << sum(2, 6) << endl;

	int array[5] = { 1, 9, -2, 8, 6 };
	cout << big(2, 3) << endl;
	cout << big(array, 5) << endl;
	
	return 0;
}