#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// *(자료형 *)p 로 void pointer를 사용하여 메모리 접근(참조 시에 명시적으로 자료형 명시하는것)
// memcpy(void*, void*, size);
void swap(void*, void*, int);

void swap(void* a, void* b, int c) {

	if (c == 1) {
		char temp;
		temp = *(char*)a;
		*(char*)a = *(char*)b;
		*(char*)b = temp;
	}
	else {
		int temp;
		temp = *(int*)a;
		*(int*)a = *(int*)b;
		*(int*)b = temp;
	}
}


int main() {

	char ch1 = 'A', ch2 = 'B';
	int n1 = 123, n2 = 234;

	swap(&ch1, &ch2, 1);
	printf("%c %c\n", ch1, ch2);
	swap(&n1, &n2, 2);
	printf("%d %d\n", n1, n2);

	return 0;
}