#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
 //사칙연산을 함수포인터배열에 적용, add, sub ,mul, div -> 1,2,3,4에 각각 대입. 각각의 함수에서 두 수를 입력받음. 두 수 입력은 각각의 함수에서 실행
int add();
int sub();
int mul();
int div();

int main() {
	int (*fptr[4])();

	fptr[0] = add;
	fptr[1] = sub;
	fptr[2] = mul;
	fptr[3] = div;

	int choice;
	printf("1-4 중 하나 입력 : ");
	scanf("%d", &choice);

	if (choice == 1) fptr[0]();
	else if (choice == 2) fptr[1]();
	else if (choice == 3) fptr[2]();
	else fptr[0]();
}

int add() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", a + b);
}

int sub() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", a - b);
}

int mul() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", a * b);
}

int div() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", a / b);
}

