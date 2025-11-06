#include "chaseok.h"
void delete(int* cnt_ptr, STUDENT** HEAD, STUDENT** TAIL) { // 학생 이름으로 삭제
	printf("삭제 선택\n");
	if (*HEAD == NULL) {
		printf("삭제할 학생이 없습니다.\n");
		return;
	}
	char search[20];
	printf("삭제할 학생의 이름을 입력하세요 : ");
	fgets(search, sizeof(search), stdin);
	search[strcspn(search, "\n")] = '\0';

	STUDENT* temp = *HEAD;
	STUDENT* btemp = NULL;
	int found = 0;
	while (temp != NULL) {
		if (!strcmp(search, temp->name)) {
			found = 1;
			break;
		}
		btemp = temp;
		temp = temp->next;
	}
	if (found) {
		if (temp == *HEAD) {
			*HEAD = temp->next;
			if (*HEAD == NULL) {
				*TAIL = NULL;
			}
		}
		else btemp->next = temp->next;
		if (temp == *TAIL) {
			*TAIL = btemp;
		}
		free(temp);
		(*cnt_ptr)--;
		printf("%s 학생의 정보를 삭제했습니다.\n", search);
	}
	else {
		printf("해당 학생을 찾을 수 없습니다.\n");
	}

	// 순회하며 삭제 데이터보다 높은 인덱스로 덮어씌우기

}