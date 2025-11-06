#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int nums1[5];
	int nums2[5];
	float avg[5];
	int arr_len = 5;
	printf("첫번째 배열의 원소들을 입력하세요\n");
	for (int i = 0; i < arr_len; i++)
	{
		scanf("%d", &nums1[i]);
	}
	printf("두번째 배열의 원소들을 입력하세요\n");
	for (int i = 0; i < arr_len; i++)
	{
		scanf("%d", &nums2[i]);
		avg[i] = ((float)(nums1[i] + nums2[i])) / 2;
	}
	
	printf("첫번째와 두번째 배열 각 위치들의 평균은\n");
	for (int i = 0; i < arr_len; i++)
	{
		printf("%f\t", avg[i]);
	}

	printf("\n각 위치의 원소들의 순위는\n");
	for (int i = 0; i < arr_len; i++)
	{
		int rank = 1;
		for (int j = 0; j < arr_len; j++) {
			if (avg[i] < avg[j]) rank++;
		}
		printf("%d 번 위치 : %d등\n", i + 1, rank);
	}

	return 0;
}