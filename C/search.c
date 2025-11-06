#include "chaseok.h"
void search(int* cnt_ptr, STUDENT** HEAD, STUDENT** TAIL) { // 학생 이름으로 검색
	printf("검색 선택\n");
	char search[20];
	fgets(search, sizeof(search), stdin);
	search[strcspn(search, "\n")] = '\0';

	int found = 0;
	STUDENT* temp = *HEAD;
	while (temp != NULL) {
		if (!strcmp(search, temp->name)) {
			found = 1;
			break;
		}
		temp = temp->next;
	}
	if (!found) {
		printf("존재하지 않는 학생 이름 입니다.\n");
		return;
	}
	else {
		printf("c\tcpp\tpython\tavg\n");
		printf("------------------------------\n");
		printf("%d\t%d\t%d\t%.1f\n", temp->c, temp->cpp, temp->python, temp->avg);
	}
}