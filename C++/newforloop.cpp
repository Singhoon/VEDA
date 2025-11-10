#include <iostream>
/*
int main() {
    int x = 5;
    int& lref = x; // l-value reference initialized with l-value x
    int&& rref = 5; // r-value reference initialized with r-value 5
    // int& r = 5; // Rvalue¶ó¼­ ¾ÈµÊ
    std::cout << "lref: " << lref << std::endl;
    std::cout << "rref: " << rref << std::endl;
    return 0;
}
*/
void fun(const int& lref) // l-value arguments will select this function
{
	std::cout << "l-value reference to const: " << lref << '\n';
	//lref = 10;
}
void fun(int&& rref) // r-value arguments will select this function
{
	std::cout << "r-value reference: " << rref << '\n';
	rref = 10;
	std::cout << "r-value reference: " << rref << '\n';
}
int main()
{
	int x{ 5 };
	fun(x); // l-value argument calls l-value version of function
	fun(5); // r-value argument calls r-value version of function
	return 0;
}