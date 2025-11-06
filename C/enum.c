#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// 키보드에서 숫자를 입력해서 색깔 출력
int main() {
	// enum { red=10, yellow, green } sign; 이러면 10,11,12 순으로 매칭됨
	enum { red=10, yellow=20, green=30 } sign;

	int c;
	scanf("%d", &c);
	switch (c) {
	case red:
		printf("red\n");
		break;
	case yellow:
		printf("yellow\n");
		break;
	case green:
		printf("green\n");
		break;
	default:
		printf("해당 색이 없음.\n");
	}
}