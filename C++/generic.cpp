#include <iostream>

using namespace std;

// 배열의 합을 사이즈만큼 누적시킨다 매개변수로 배열, 배열의 요소 갯수
//변환형 add(arr, num) {}

template <typename T> // <class T1, classT2> 이렇게 가능
T add(T arr[], int len) {
	T sum = (T)0;
	for (int i = 0; i < len; i++) sum += arr[i];
	return sum;
}

int main() {
	
	int arr1[5] = { 1,2,3,4,5 };
	int result1 = add<int>(arr1, 5);
	cout << result1 << endl;

	double arr2[5] = { 1.1,2.2,3.3,4.4,5.5 };
	double result2 = add<double>(arr2, 5);
	cout << result2 << endl;

	return 0;
}