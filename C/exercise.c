#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
// +-*/ 함수 기반으로 작성

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

int div(int a, int b) {
	return a / b;
}

int main() {
	int num1, num2;
	char op;
	int result;

	scanf("%d %c %d", &num1, &op, &num2);

	switch (op) {
	case '+':
		result = add(num1, num2);
		printf("%d %c %d = %d", num1, op, num2, result);
		break;
		
	case '-':
		result = sub(num1, num2);
		printf("%d %c %d = %d", num1, op, num2, result);
		break;

	case '*':
		result = mul(num1, num2);
		printf("%d %c %d = %dt", num1, op, num2, result);
		break;

	case '/':
		result = div(num1, num2);
		printf("%d %c %d = %d", num1, op, num2, result);
		break;
	}

	return 0;
}