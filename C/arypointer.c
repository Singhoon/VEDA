#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int ary[3];
	int* pa = ary;
	printf("%d\n", sizeof(ary));
	printf("%d\n", sizeof(pa));
	int i;

	*pa = 10;
	*(pa + 1) = 20;
	pa[2] = pa[0] + pa[1];

	for (i = 2; i > -1; i--)
	{
		printf("%5d", *(pa + i));
	}
	return 0;
}