#include <iostream>
#include <string>
// c++ 에서 구조체 선언에서 아명은 안적어도 됨
using namespace std;

struct Person {
	string name;
	int age;
	float height;
	float weight;
};

void check_age(Person* p, int count) {
	for (int i = 0; i < count; i++) {
		if (p[i].age > 25) {
			cout << "name : " << p[i].name << endl;
			cout << "age : " << p[i].age << endl;
			cout << "height : " << p[i].height << endl;
			cout << "weight : " << p[i].weight << endl;
		}
	}
}
int build_person_and_check(int& ref) {

	string name_info[10] = {"Brain", "Jessica", "James", "Eric", "John", "Tom", "Tomy", "Alice", "Bob", "Carol"};
	int age_info[10] = { 24, 22, 30, 28, 35, 40, 25, 27, 32, 29 };
	float height_info[10] = { 180, 165, 170, 172, 168, 175, 169, 181, 163, 177 };
	float weight_info[10] = { 70, 55, 65, 68, 62, 75, 57, 73, 60, 80 };

	int size;
	cout << "배열의 전체 크기를 입력하세요: ";
	cin >> size;
	// 구조체의 배열 만들기
	Person* p = new Person[size];
	for (int i = 0; i < size; i++) {
		ref++;
		p[i].name = name_info[i];
		p[i].age = age_info[i];
		p[i].height = height_info[i];
		p[i].weight = weight_info[i];
	}
	check_age(p, size);
	delete[] p;
	p = nullptr;

	// cout << &ref << endl;
	return 0;
}

int main() {
	int num = 0;
	build_person_and_check(num);
	build_person_and_check(num);
	build_person_and_check(num);
	cout << num << endl;
	return 0;
}