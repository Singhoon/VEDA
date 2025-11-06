#include <iostream>

using namespace std;
// 상응하는 catch문이 없으면 상위에서 확인한다


void func_thorw() {
	cout << "func_throw()" << endl;
	cout << "throw -1" << endl;
	throw - 1;
	cout << "after throw -1" << endl;
}

int main() {

	try {
		func_thorw();
	}
	catch (int exec) {
		cout << "catch " << exec << endl;
	}

	return 0;
}