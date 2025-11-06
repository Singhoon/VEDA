#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num[10];

	for (int i = 0; i < 10; i++)
	{
		//scanf("%d", &num[i]);
		scanf("%d", num + i);
	}
	int found = 0;
	int position;
	for (int i = 0; i < 10; i++)
	{
		if (num[i] == 10) {
			position = i + 1;
			found = 1;
			printf("%d 번째\n", position);
		}
	}
	if (!found)  printf("못찾았습니다.");
	return 0;
}