#include <iostream>
#include <string>

// default 매개 변수를 사용하면 함수중복을 간소화 시킴
// 중복 함수들과 디폴트 매개 변수를 가진 함수를 함께 사용 불가
using namespace std;

void f(char c = '_', int lines = 1, int num = 10) {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < num; j++) {
            cout << c;
        }
        cout << endl;
    }
}

int main()
{
    f();
    f('%');
    f('@', 5);

    return 0;
}