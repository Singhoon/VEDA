#include <iostream>

// 자료형& 레퍼런스변수이름 = 대상변수이름 -> 레퍼런스변수는 무조건 초기화를 시켜야 함(별명이기 때문에. 원본이 아님)
// 레퍼런스 변수 내용 변경 -> 원본 변경도 됨 -> 역방향도 가능
// 상수값은 초기화가 안된다. const int& r = 100; 은 가능하다.
// 반환값을 레퍼런스변수로 설정가능하다
// 포인터를 쓰다 보면 별 같은 연산자 써서 불편함. 레퍼런스변수는 추가 연산자 없이 간단하게 사용가능
using namespace std;


void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	/*
	int n;
	int& r = n;
	
	cin >> n;
	cout << r << endl;
	*/

	int x = 5;
	int y = 6;
	swap(x, y);

	cout << x << ' ' << y << endl;

	return 0;
}
