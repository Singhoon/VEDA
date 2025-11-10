#include <iostream>
#include <memory>

using namespace std;

class Base {
public:
	virtual void bar() { cout << "Base::bar()\n"; }
	virtual ~Base() { cout << "~Base" << std::endl; }
};
class Derived : public Base {
public:
	virtual ~Derived() {
		cout << "~Derived\n";
	}
	virtual void bar() override { cout << "Derived::bar()\n"; }
};

int main() {

	/*
	auto ptr = make_unique<int>(10);
	cout << ptr.get() << endl;
	cout << "*ptr : " << *ptr << endl;
	// auto ptr = new int(10);
	//
	// delete ptr;
	*/

	auto ptr = make_unique<Derived>();
	cout << ptr.get() << endl;
	ptr->bar();

	// auto ptr2 = ptr; 다른 포인터가 unique_ptr과 같은 곳을 가르킬 수 없다


	return 0;
}