#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char str1[80], str2[80];

	printf("첫번째 문자열 입력 : ");
	scanf("%s", str1);

	if (sizeof(str2) > strlen(str1)) { //str1 대신에 "apple"같이 직접 문자열을 넣을 수 있다. 문자열은 주소값이기 때문.
		strcpy(str2, str1);
		printf("복사된 두번째 문자열 출력 : %s", str2);
	}
	return 0;
}