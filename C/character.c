#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	
	char ch;
	int num;

	while (1) {
		printf("num : ");
		scanf("%d", &num);

		if (num == -1) break;
		getchar();
		printf("ch : ");
		ch = getchar();

		printf("num : %d, ch : %c\n", num, ch);
	}
	return 0;
}