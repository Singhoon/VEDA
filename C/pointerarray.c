#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
// p++하면 다음행이다. 20이라고 넣어줘야 p의 단위가 20이라는 것을 알린다. 그래서 names 각각의 행 처리가능.

void func(char*);

int main() {
	
	char names[3][20] = { "kim", "lee", "park" };
	func(names);
	return 0;
}

void func(char(*p)[20]) {
	for (int i = 0; i < 3; i++) {
		printf("%s\n", p[i]);
	}
}