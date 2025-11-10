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

	auto ptr = make_shared<Derived>();
	cout << ptr.get() << endl;
	ptr->bar();
	cout << ptr.use_count() << endl;

	auto ptr2 = ptr;
	cout << ptr.use_count() << endl;

	return 0;
}