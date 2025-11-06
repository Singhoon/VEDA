#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	char ch, * cp;
	int num, * pnum;
	float fnum, * pfnum;
	double dnum, * dfnum;

	cp = &ch;
	pnum = &num;
	pfnum = &fnum;
	dfnum = &dnum;

	printf("1. &p %p %p %p\n", &ch, &num, &fnum, &dnum);
	printf("2. &p %p %p %p\n", cp, pnum, pfnum, &dfnum);


	return 0;
}