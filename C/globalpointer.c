#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int*, int*);

void swap(int* x, int* y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main() {
	int x = 100, y = 200;
	scanf("%d %d", &x, &y);
	swap(&x, &y);
	printf("%d %d", x, y);

	return 0;
}