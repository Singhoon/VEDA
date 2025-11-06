#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> vec;

	int enter;
	
	while (true) {
		cin >> enter;
		if (enter == -1) break;
		vec.push_back(enter);
		// vector[index] 이렇게는 안된다. 동적 메모리 이기 때문
	}
	

	vector<int>::iterator it = vec.begin();
	/*
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << *it << endl;
	}
	*/
	int size = vec.size();
	for (int i = 0; i < size; i++) cout << vec.at(i) << endl;

	// cout << vec.at(10) << endl;

	return 0;
}