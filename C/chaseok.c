// 매뉴 출력 및 선택

#include "chaseok.h"

int main() {

	// 배열 대신에 head와 tail을 선언해서 input
	// 변수 선언
	STUDENT* HEAD, * TAIL;
	HEAD = TAIL = NULL;


	int menuNo;
	int cnt = 0;	// 학생 수

	void (*fptr[4])(int* cnt, STUDENT** HEAD, STUDENT** TAIL);

	fptr[0] = input;
	fptr[1] = output;
	fptr[2] = search;
	fptr[3] = delete;

	printf("=======\n"
		"1. 입력\n"
		"2. 출력\n"
		"3. 검색\n"
		"4. 삭제\n"
		"5. 종료\n"
		"=======\n\n");

	do {
		printf("\n메뉴 번호를 선택해주세요: ");
		scanf("%d", &menuNo);
		getchar();

		if (menuNo >= 1 && menuNo <= 4) {
			fptr[menuNo - 1](&cnt, &HEAD, &TAIL);
		}
		else if (menuNo == 5) {
			printf("시스템을 종료합니다.\n");
			break;
		}
		else {
			printf("잘못 선택 하셨습니다.\n");
		}
		
	} while (1);


	return 0;
}







