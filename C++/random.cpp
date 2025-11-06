#include <iostream>
#include <cstdlib> // C++의 stdlib.h
#include <ctime>   // C++의 time.h
#include <string> 

using namespace std;

void game() {
	srand(time(nullptr));

	int com_choice = rand() % 3;
	int user_choice;
	cout << "가위(0), 바위(1), 보(2) 를 선택하세요: ";
	cin >> user_choice;
	while (1) {
		if (user_choice >= 0 && user_choice <= 2) break;
		else {
			cout << "잘못된 입력입니다. 0, 1, 2 중 하나를 입력하세요: ";
			cin >> user_choice;
		}
	}
	string choices[3] = { "가위", "바위", "보" };
	cout << "--- 결과 ---" << endl;
	cout << "유저: " << choices[user_choice] << endl;
	cout << "컴퓨터: " << choices[com_choice] << endl;

	if (user_choice == com_choice) {
		cout << "비겼습니다!" << endl;
	}
	else if (user_choice == (com_choice + 1) % 3) {
		cout << "유저 승리!" << endl;
	}
	else {
		cout << "컴퓨터 승리!" << endl;
	}
}

int main() {
	int cnt = 0;
	while (cnt <= 10) {
		if (cnt == 10) {
			char cont;
			cout << "계속하시겠습니까?(y/n) : ";
			cin >> cont;
			if (cont == 'y') {
				cnt = 0;
				continue;
			}
			else break;
		}
		else {
			game();
			cnt++;
		}
	}

	return 0;
}