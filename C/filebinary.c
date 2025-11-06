#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "type.h"
#define MAX 5

int main() {
	// int count = 3;

	FILE* fp;
	type p[MAX] = { {1,1.1,"apple"}, {2,2.2,"grape"}, {3,3.3,"pear"} };

	fp = fopen("memo.dat", "wb");
	if (fp == NULL) {
		fprintf(stderr, "cannot open memo.dat file\n");
		return 1;
	}
	fwrite(&p, sizeof(p), 1, fp);
	fclose(fp);
	
	for (int i = 0; i < MAX; i++) {
		p[i].n = 0;
		p[i].fnum = 0.0;
		strcpy(p[i].str, "");
	}
	fp = fopen("memo.dat", "rb");
	if (fp == NULL) {
		fprintf(stderr, "cannot open memo.dat file\n");
		return 1;
	}
	/*
	int c = sizeof(type);
	//fread(&count, sizeof(int), 1, fp);
	fseek(fp, -c, SEEK_END);
	fread(&p[0], sizeof(type), 1, fp);
	printf(" %d %f %s\n", p[0].n, p[0].fnum, p[0].str);
	*/
	for (int i = 0; i < MAX; i++) {
		fread(&p[i].n, sizeof(int), 1, fp);
		fread(&p[i].fnum, sizeof(float), 1, fp);
		fread(p[i].str, 80, 1, fp);
	}
	fclose(fp);
	for (int i = 0; i < MAX; i++) {
		printf("%d %f %s\n", p[i].n, p[i].fnum, p[i].str);
	}

	return 0;
}