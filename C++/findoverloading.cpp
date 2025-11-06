#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Circle {
public:
	int radius;
	string name;
	bool operator==(const Circle& other) const {
		return radius == other.radius;
	}
};

int main() {

	vector<Circle> vec = { Circle(5),Circle(8),Circle(9),Circle(7) };
	vector<Circle>::iterator it = find(vec.begin(), vec.end(), Circle(8));

	if (it != vec.end()) cout << "찾은 위치 : " << distance(vec.begin(), it) << endl;
	else cout << "찾을 수 없음" << endl;



	return 0;
}