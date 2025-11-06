#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input(int*);

void input(int* pa) {
	
	for (int i = 0; i < 3; i++) {
		scanf("%d", pa + i);
	}
}

int main() {
	int ary[3];
	int* pa = ary;
	
	input(pa);

	for (int i = 0; i < 3; i++)
	{
		printf("%5d", *(ary + i));
	}
	return 0;
}