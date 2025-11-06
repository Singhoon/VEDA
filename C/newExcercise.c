#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isPrime(int);

int isPrime(int input) {
	int is_prime = 1;
	for (int i = 2; i <= input - 1 ; i++)
	{
		if (input % i == 0) return 0;
	}
	return 1;
}

int main() {
	int num, ans;
	printf("숫자를 입력하세요 : ");
	scanf("%d", &num);
	printf("2부터 %d 중에서..\n", num);
	for (int i = 2; i <= num; i++)
	{
		ans = isPrime(i);
		if (ans) printf("%d는 소수입니다\n", i);
	}
	return 0;
}