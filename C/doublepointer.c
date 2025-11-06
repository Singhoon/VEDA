#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int n = 100;
	int* p;
	int** dp;

	p = &n;
	dp = &p;

	scanf("%d", p);
	scanf("%d", dp);
	printf("%d %d %d", n, *p, **dp);

	return 0;
}