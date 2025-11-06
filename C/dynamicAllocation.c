#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// p = (type*)malloc(size)
// p = (type*)malloc(sizeof(type))
// malloc의 리턴값은 void포인터이다
// malloc으로 할당받은 포인터는, 배열처럼 활용도 가능 p[0], *(p+2) 등등..
// calloc(size, count) 
// realloc(ptr,size)
// free(ptr)

int main() {

	int* p;
	
	p = (int*)malloc(sizeof(int)*5);
	if (p == NULL) {
		printf("error : malloc failed\n");
		return 1;
	}
	for (int i = 0; i < 5; i++) {
		scanf("%d", p + i);
	}
	for (int i = 0; i < 5; i++) {
		printf("*p : %d\n", *(p + i));
	}
	p = realloc(p, sizeof(int) * 10);

	for (int i = 5; i < 10; i++) {
		scanf("%d", p + i);
	}
	for (int i = 0; i < 10; i++) {
		printf("*p : %d\n", *(p + i));
	}
	p = realloc(p, sizeof(int) * 10);

	free(p);

	return 0;
}