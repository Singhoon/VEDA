#include <iostream>
#include <set>

using namespace std;

int main() {

	set<int> mySet;

	mySet.insert(5);
	mySet.insert(2);
	mySet.insert(8);

	if (mySet.find(5) != mySet.end()) cout << "5는 set에 저장되어 있음" << endl;
	// if (mySet.find(6) != mySet.end()) cout << "5는 set에 저장되어 있음" << endl; -> 없는 원소이기 때문에 이 줄은 넘어가짐

	for (auto it = mySet.begin(); it != mySet.end(); ++it) cout << *it << " ";
	
	cout << endl;

	int size = mySet.size();
	cout << "mySet의 크기: " << size << endl;




	return 0;
}