#include <iostream>
#include <string> // string 사용을 위해 추가

using namespace std;

template <typename T = int>
class data_package {
public:
	data_package(T first) : first(first) {}

	// 이 함수는 data_package<T>의 멤버가 아니라,
	// data_package<T>의 private 멤버에 접근할 수 있는 "친구"라고 선언
	friend void printout_friend_element(data_package<T>& data_object);

private:
	T first;
};

// 'friend' 함수는 클래스 멤버가 아니므로 'data_package<T>::'를 제거하고
// 일반 템플릿 함수로 정의합니다.
template <typename T>
void printout_friend_element(data_package<T>& data_object) {
	// 'friend'로 선언되었기 때문에 private 멤버인 data_object.first에 접근 가능
	cout << "(friend 함수 호출) 템플릿 매개변수 값 : " << data_object.first << endl;
}

int main() {
	// T의 기본값이 int이므로 data_package<int>와 동일
	data_package<> template_inst1(5);
	data_package<string> template_inst2("클래스 템플릿 기본값이 아닌 string형");

	printout_friend_element(template_inst1);
	printout_friend_element(template_inst2);

	return 0;
}