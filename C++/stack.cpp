// 정수형 배열 --> 생성할 때 배열의 크기를 인자전달. 인자전달 없으면 10개이다. pop은 return 대신 매개변수로 받아온다. 리턴값은 실패 시 false
#include <iostream>

using namespace std;

template <class T>
class Stack {
private: 
	int size, top;
	T* array;
	bool isEmpty();
	bool isFull();
public:
	//Stack<T>();->생성자 삭제
	Stack(int a = 10);
	~Stack();
	Stack<T>(const Stack<T>& other); // 복사 생성자 선언 추가
	Stack<T>& operator=(const Stack<T>& other); // 복사 할당 연산자 선언
	bool push(T);
	bool pop(T&);
};
/*
template <class T>
Stack<T>::Stack() {

}
*/
template <class T>
Stack<T>::Stack(int a) {
	size = a;
	top = -1;
	array = new T[size];
	/*
	for (int i = 0; i < size; i++) {
		*(array + i) = -1;
	}
	*/
	cout << size << "크기의 스택을 생성하였습니다." << endl;
}
template <class T>
Stack<T>::~Stack() {
	delete[] array;
	array = nullptr;
	cout << "스택을 해제하였습니다." << endl;
}
// deep copy 생성자 구현
template <class T>
Stack<T>::Stack(const Stack<T>& other) {
	// 1. 일반 멤버(값) 복사
	size = other.size;
	top = other.top;

	// 2. (핵심) 포인터(array)를 위한 새 메모리를 할당
	array = new T[size];

	// 3. (핵심) 원본 배열의 "내용"을 "새" 배열로 복사
	// (전체 배열(i < size)을 복사해도 되지만, top까지만 복사하는 것이 더 효율적)
	for (int i = 0; i <= top; i++) {
		array[i] = other.array[i];
	}

	cout << size << "크기의 스택을 '깊은 복사' 하였습니다." << endl;
}
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
	cout << other.size << "크기 스택의 '깊은 복사 할당'이 일어났습니다." << endl;

	// 1. 자기 자신에게 할당하는지 확인 (s1 = s1 같은 경우)
	if (this == &other) {
		return *this; // 자기 자신을 그대로 반환
	}

	// 2. (중요) 내가(s2) 원래 가지고 있던 메모리(B)를 해제
	delete[] array;

	// 3. (복사 생성자와 동일) 값 멤버 복사
	size = other.size;
	top = other.top;

	// 4. (복사 생성자와 동일) 새 메모리(C)를 할당
	array = new T[size];

	// 5. (복사 생성자와 동일) 데이터 내용 복사
	for (int i = 0; i <= top; i++) {
		array[i] = other.array[i];
	}

	// 6. (관례) *this를 반환하여 (a = b = c) 같은 연쇄 할당 지원
	return *this;
}
template <class T>
bool Stack<T>::push(T a) {
	if (!isFull()) {
		top += 1;
		array[top] = a;
		return true;
	}
	else {
		cout << "push할 수 없습니다." << endl; 
		return false;
	}
}
template <class T>
bool Stack<T>::pop(T& a) {
	if (!isEmpty()) {
		a = *(array + top);
		//*(array+top) = -1; -> 필요 없는 부분(string일때 문제생김)
		top--;
		return true;
	}
	else{
		cout << "pop할 수 없습니다." << endl;
		return false;
	}
}
template <class T>
bool Stack<T>::isEmpty() {
	if (top == -1) return true;
	else return false;
}
template <class T>
bool Stack<T>::isFull() {
	if (top == size - 1) return true;
	else return false;
}

int main() {
	Stack<int> n;
	n.push(3);
	n.push(7);

	int nTemp;
	n.pop(nTemp);
	cout << nTemp << endl;
	n.pop(nTemp);
	cout << nTemp << endl;
	Stack<double> d;
	d.push(1.5);
	d.push(1.2);
	double dTemp;
	d.pop(dTemp);
	cout << dTemp << endl;
	d.pop(dTemp);
	cout << dTemp << endl;
	Stack<char> c;
	c.push('a');
	c.push('c');
	char cTemp;
	c.pop(cTemp);
	cout << cTemp << endl;
	c.pop(cTemp);
	cout << cTemp << endl;
	Stack<string> s;
	s.push("str111");
	s.push("str222");
	string sTemp;
	s.pop(sTemp);
	cout << sTemp << endl;
	s.pop(sTemp);
	cout << sTemp << endl;
	return 0; // 여기서 s2 소멸, s1 소멸 (에러 없이 종료됨)
}