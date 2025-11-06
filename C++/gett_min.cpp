#include <iostream>
#include <string>

using namespace std;


int getMin(int a, int b) {
	if (a <= b) return a;
	else return b;
}

double getMin(double a, double b) {
	if (a <= b) return a;
	else return b;
}

char getMin(char a, char b) {
	if (a <= b) return a;
	else return b;
}

string getMin(string a, string b) {
	if (a <= b) return a;
	else return b;
}

int getMin(int array[], int size) {
	int max = array[0];
	for (int i = 1; i < size; i++) {
		if (array[i] < max) max = array[i];
	}
	return max;
}

int main()
{
    int a, b;
    cout << "두개의 정수를 입력하세요 : ";
    cin >> a >> b;
    cout << "최소값은 " << getMin(a, b) << "입니다.\n";

    double c, d;
    cout << "두개의 실수를 입력하세요 : ";
    cin >> c >> d;
    cout << "최소값은 " << getMin(c, d) << "입니다.\n";

    string s1, s2;
    cout << "두개의 문자열을 입력하세요 : ";
    cin >> s1 >> s2;
    cout << "최소값은 " << getMin(s1, s2) << "입니다.\n";

    // 배열 크기를 10으로 고정
    const int ARR_SIZE = 10;
    int arr[ARR_SIZE] = { 2, 19, 34, 387, 1, 45, 78, 45, 11, 29 };

    cout << "배열의 원소 : ";
    // for 루프에서 고정된 크기 10 대신 ARR_SIZE 사용
    for (int i = 0; i < ARR_SIZE; i++)
        cout << arr[i] << " ";

    cout << "\n최소값은 " << getMin(arr, ARR_SIZE) << "입니다.\n";

    return 0;
}