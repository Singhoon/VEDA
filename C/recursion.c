#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int recursion(int);

int recursion(int num) {
	if (num == 1) return 1;
	return num * recursion(num - 1);
}
int main() {
	int num, ans;
	scanf("%d", &num);
	ans = recursion(num);
	printf("%d의 팩토리얼 값은 %d 입니다.\n", num, ans);
	return 0;
}