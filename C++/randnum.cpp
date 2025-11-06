#include <iostream>
#include <random>
#include <chrono>
using namespace std;

int main() {

	auto millis = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
	mt19937_64 mt_rand(millis);

	for (int i = 0; i < 10; i++) {
		cout << mt_rand() << endl;
	}

	return 0;
}