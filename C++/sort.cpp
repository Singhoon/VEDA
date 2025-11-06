#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

struct Circle {
	int radius;
};

bool compare(const Circle& left, const Circle& right) {
	return left.radius < right.radius;
}

int main() {

	vector<Circle> vec;
	vec.push_back(Circle(15));
	vec.push_back(Circle(10));
	vec.push_back(Circle(3));
	vec.push_back(Circle(8));

	for (vector<Circle>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << it->radius << '\t';
	}
	cout << endl;

	sort(vec.begin(), vec.end(), compare);

	for (vector<Circle>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << it->radius << '\t';
	}
	cout << endl;

	return 0;
}

