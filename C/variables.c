#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int* sum(int, int);

static int count = 0; //전역변수에 static을 붙이면, 이 파일 안에서만 변수 참조 가능
int main() {
	int* resp;

	resp = sum(10, 20);
	printf("두 정수의 합 : %d\n", *resp);

	return 0;
}

int* sum(int a, int b) {
	static int res;

	res = a + b;

	return &res;
}