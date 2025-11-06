#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// fopen의 return값은 파일포인터 
// fgetc, fputc, fgets, fputs, fscanf, fprintf, fclose -> 이 함수들을 부르면 순차적으로 읽는다
// fprintf는 문자열로 바꿔서 출력(파일의 크기가 커진다
// fread,fwrite 두 개는 파일에 있는 바이트 단위 그대로 읽는다 --> fscanf랑 fprintf는 문자열로 변환 후 작업한다
int main() {

	FILE* fp;
	int num = 10;
	float fnum = 123.45;
	char str[80] = "abcdef";

	fp = fopen("memo.txt", "w");
	if (fp == NULL) {
		printf("cannot open file memo.txt");
		return 1;
	}
	fprintf(fp, "%d %f %s\n", num, fnum, str);
	fclose(fp);
	num = 0; fnum = 0; strcpy(str, "");

	fp = fopen("memo.txt", "r");
	fscanf(fp, "%d %f %s", &num, &fnum, str);
	printf("%d %f %s", num, fnum, str);
	fclose(fp);

	return 0;
}