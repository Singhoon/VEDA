#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<string> vec;

	string line;
	for (int i = 0; i < 5; i++) {
		cin >> line;
		vec.push_back(line);
	}
	/*
	line = vec[0];
	for (int i = 1; i < 5; i++) {
		if (vec.at(i) > line) line = vec.at(i);
	}

	cout << line << endl;
	*/

	int position;
	string element;
	for (int i = 0; i < 3; i++) {
		cout << "넣을 원소 : ";
		cin >> element;
		cout << "넣을 위치 : ";
		cin >> position;

		vec.insert(vec.begin() + position, element);
	}

	for (int i = 0; i < 3; i++) {
		cout << "뺄 위치 : ";
		cin >> position;

		vec.erase(vec.begin() + position);
	}

	return 0;
}