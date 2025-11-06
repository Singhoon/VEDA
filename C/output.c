#include "chaseok.h"
void output(int* cnt_ptr, STUDENT** HEAD, STUDENT** TAIL) {
	printf("출력 선택\n");
	float c_sum = 0, cp_sum = 0, py_sum = 0;

	printf("name\tc\tcpp\tpython\tavg\n");
	printf("-----------------------------------\n");
	STUDENT* temp = *HEAD;
		while (temp != NULL) {
			printf("%s\t%d\t%d\t%d\t%.1f\n", temp->name, temp->c, temp->cpp, temp->python, temp->avg);
			c_sum += temp->c;
			cp_sum += temp->cpp;
			py_sum += temp->python;
			temp = temp->next;
		}
	printf("---------------avg-----------------\n");
	if (*cnt_ptr > 0) {
		printf("\t%.1f\t%.1f\t%.1f\n", c_sum / *cnt_ptr, cp_sum / *cnt_ptr, py_sum / *cnt_ptr);
	}
	else {
		printf("입력된 학생이 없습니다.\n");
	}
}