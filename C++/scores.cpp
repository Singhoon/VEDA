#include <iostream>

using namespace std;
// input함수에서 입력을 받고 예외처리를 한다. 
// try 안에 input함수를 호출한다. 이건 main에서 지정을 한다. 예외발생은 input함수에서 한다
// integer값이 아닌 다른 값이 들어오면 trycatch블록으로 만듣다 
// 5명의 시험 성적을 입력하는데, 성적이 잘못들어오면 예외처리. 정상적으로 들어오면 정상적으로 입력받은 학생에 한해서는 평균값을 구한다

// 5명의 학생 성적 입력 - input() 함수 처리
//  성적 점수 (0-100)
// 예외 발생 처리 - main()에서 예외처리
// 정상 점수만 평균 계산 - main()에서 처리

int input(string& str) {

	for (int i = 0; i < 5; i++) {
		cin >> scores[i];
	}

	return 0;
}

int main() {

	int scores[5], count = 5;
	float avg = 0;
	string str;

	for (int i = 0; i < 5; ++i) {
		try {
			input(str);
		}
		catch (string& str) {
			count--;
			if str == "under" {

		}
	}
	
	return 0;
}
