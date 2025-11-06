#include <iostream>
#include <list>

using namespace std;

int main() {

	list<int> myList;

	myList.push_back(1);
	myList.push_back(3);
	myList.push_front(6);
	myList.push_front(8);

	for (int value : myList) cout << value << ' ';
	cout << endl;

	myList.pop_front();
	myList.pop_back();

	for (int value : myList) cout << value << ' ';
	cout << endl;

	cout << "리스트 크기 : " << myList.size() << endl;
	cout << "리스트가 비었나? : " << (myList.empty() ? "예" : "아니오") << endl;
	return 0;
}