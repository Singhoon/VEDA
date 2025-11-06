#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	struct style {
		char name[20];
		int weight;
		float height;
	};

	struct style st1, st2, * p;
	p = &st1;

	scanf("%s", p->name);
	scanf("%d %f", &p->weight, &p->height); getchar();

	printf("%s %d %.1f\n", p->name, p->weight, p->height);

	st2 = *p;
	printf("%s %d %.1f\n", st2.name, st2.weight, st2.height);

	return 0;
}