#include "chaseok.h"

void input(int* cnt_ptr, STUDENT** HEAD, STUDENT** TAIL) {
	printf("입력 선택\n");

	while (*cnt_ptr < 30) {
		STUDENT* temp;
		temp = (STUDENT*)malloc(sizeof(STUDENT));
		if (temp == NULL) {
			printf("malloc failed\n");
			return;
		}
		printf("학생의 성적을 입력하세요. (종료시 : 학생 성적 중 한 과목 이상에 -1 입력) : ");
		scanf("%d %d %d", &temp->c, &temp->cpp, &temp->python);
		getchar();
		if (temp->c == -1 || temp->cpp == -1 || temp->python == -1) {
			free(temp);
			printf("학생 점수 입력을 종료합니다.\n");
			break;
		}
		printf("학생의 이름을 입력하세요 : ");
		fgets(temp->name, sizeof(temp->name), stdin);
		temp->name[strcspn(temp->name, "\n")] = '\0';
		temp->avg = (float)(temp->c + temp->cpp + temp->python) / 3;
		temp->next = NULL;
		if (*HEAD == NULL) {
			*HEAD = *TAIL = temp; //첫번째노드
		}
		else {
			(*TAIL)->next = temp;
			*TAIL = temp;
		}
		(*cnt_ptr)++;
		printf("%s 학생의 성적입력이 완료되었습니다.\n\n", temp->name);
	}
}