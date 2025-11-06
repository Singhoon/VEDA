#include <stdio.h>
#define _CRT_SECURE_NO_WARININGS
int main(void) 
{
	int left, right;
	char operator;

	scanf("%d %c %d", &left, &operator, &right);

	switch (operator) {
	case '+':
		printf("%d",left + right);
		break;
	case '-':
		printf("%d",left - right);
		break;
	case '*':
		printf("%d",left * right);
		break;
	case '/':
		printf("%d",left / right);
		break;
	default:
		printf("연산자를 잘못입력했습니다.\n");
		break;
	}
	return 0;
}