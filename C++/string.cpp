#include <iostream>
//#include <string>

using namespace std;

int main() {
	string str1;
	cin >> str1;

	//cout << str1.length() << endl;
	//cout << str1.size() << endl;

	//cout << boolalpha << str1.empty() << noboolalpha << ' ' << str1.empty() << endl;

	// append, find, compare, 

	string s1 = "hello";
	string s2 = "Hello";
	cin >> s1 >> s2;
	cout << s1.compare(s2);
}