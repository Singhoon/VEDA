// 두 문자를 입력해서 크기비교

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {
	char str1[80];
	char str2[80];

	fgets(str1, sizeof(str1), stdin);
	str1[strcspn(str1, '\n')] = '\0';
	fgets(str2, sizeof(str2), stdin);
	str2[strcspn(str2, '\n')] = '\0';

	if (strcmp(str1, str2) > 0) { printf("첫번째 문자열이 더 큽니다."); }
	else if (strcmp(str1, str2) < 0) { printf("두번째 문자열이 더 큽니다."); }
	else printf("두 문자열이 같습니다.");

	return 0;
}