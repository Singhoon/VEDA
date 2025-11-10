#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	
	int a = 10, b = 20;
	[](int& x, int& y) { int t; t = x; x = y; y = t; } (a, b);
	cout << a << ", " << b << endl;
	int sum;
	int arr[] = { 1, 2, 3, 4 };
	[&sum](int* arr, int n) { for (int i = 0; i < n; i++) sum += arr[i]; }(arr, 4);
	auto swap = [](int& x, int& y) { int t; t = x; x = y; y = t; };
	swap(a, b);
	cout << a << ", " << b << endl;
	

	// vector v의 원소 중 x와 y 사이에 있는 원소 찾기
	vector<int> v{ 1,2,3,4,5 };
	int x = 2;
	int y = 4;
	auto result = find_if(begin(v), end(v), [=](int i) { return i > x && i < y; });
	// 벡터 내의 각 요소 출력
	for_each(begin(v), end(v), [](int n) { cout << n << " "; });
	cout << endl;
	// vect2 생성
	vector<int> vect2;
	vect2.resize(v.size());
	// vector v의 요소를 제곱하여 vect2 에 저장
	transform(begin(v), end(v), begin(vect2), [](int n) { return n * n; });
	cout << "Squared Data : ";
	for_each(begin(vect2), end(vect2), [](int n) { cout << n << " "; });

	return 0;
}
