#include <iostream>
using namespace std;

// 다중상속 예시 구현

/*
class Adder {
protected:
	int add(int a, int b) { return a + b; }
};
class Subtractor {
protected:
	int sub(int a, int b) { return a - b; }
};
class Calculator : public Adder, public Subtractor {
public:
	int calc(char op, int a, int b);
};
int Calculator::calc(char op, int a, int b) {
	int result;
	
	switch (op) {
	case '+': result = add(a, b); break;
	case '-': result = sub(a, b); break;
	}
	return result;
}
*/
//연속적인 상속이 이루어짐
class BaseIO {
public:
	int mode;
};
class In : virtual public BaseIO {
public:
	int readPos;
};
class Out : virtual public BaseIO {
public:
	int writePos;
};
class InOut : public In, public Out {
public:
	bool safe;
};

int main() {
	/*
	Calculator cal;
	int result1 = cal.calc('+', 3, 4);
	int result2 = cal.calc('-', 3, 4);
	cout << result1 << ' ' << result2 << endl;
	*/

	InOut io;

	io.safe = true;
	io.readPos = 1;
	io.writePos = 2;
	io.mode = 3;

	return 0;
}