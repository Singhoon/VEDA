// 매뉴 출력 및 선택
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 함수의 반환값 :  성공하면 1 반환, 실패하면 0 반환
 /*
  입력 함수
 */
void input(int* cnt_ptr, int* c_arr, int* cp_arr, int* py_arr, float* avg_arr);

/*
 출력 함수
*/
void output(int* cnt_ptr, int* c_arr, int* cp_arr, int* py_arr);

/*
 검색 함수
*/
void search(int* cnt_ptr, int* c_arr, int* cp_arr, int* py_arr, float* avg_arr);

/*
 삭제 함수
*/
void delete(int* cnt_ptr, int* c_arr, int* cp_arr, int* py_arr, float* avg_arr);

int main() {
	int menuNo;
	// 배열선언
	int c[30] = { -1 }, cp[30] = { -1 }, py[30] = { -1 };	// 성정 배열
	float avg[30] = { -1 };									// 평균 배열
	int cnt = 0;	// 학생 수
	int ans;

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

		switch (menuNo) {
		case 1:
			input(&cnt, c, cp, py, avg);
			break;

		case 2:
			output(&cnt, c, cp, py);
			break;

		case 3:
			search(&cnt, c, cp, py, avg);
			break;

		case 4:
			delete(&cnt, c, cp, py, avg);
			break;

		case 5:
			printf("시스템을 종료합니다.\n");
			break;

		default:
			printf("잘못 선택 하셨습니다.\n");
		}
	} while (menuNo != 5);


	return 0;
}

void input(int* cnt_ptr, int* c_arr, int* cp_arr, int* py_arr, float* avg_arr) {
	printf("입력 선택\n");

	while (*cnt_ptr < 30) {
		scanf("%d %d %d", &c_arr[*cnt_ptr], &cp_arr[*cnt_ptr], &py_arr[*cnt_ptr]);

		if (c_arr[*cnt_ptr] == -1 || cp_arr[*cnt_ptr] == -1 || py_arr[*cnt_ptr] == -1) {
			printf("학생 점수 입력을 종료합니다.\n");
			break;
		}

		avg_arr[*cnt_ptr] = (float)(c_arr[*cnt_ptr] + cp_arr[*cnt_ptr] + py_arr[*cnt_ptr]) / 3;
		(*cnt_ptr)++;
	}
}

void output(int* cnt_ptr, int* c_arr, int* cp_arr, int* py_arr) {
	printf("출력 선택\n");
	float c_sum = 0, cp_sum = 0, py_sum = 0;

	printf("c\tcpp\tpython\n");
	printf("----------------------\n");
	for (int i = 0; i < *cnt_ptr; i++) {
		printf("%d\t%d\t%d\n", c_arr[i], cp_arr[i], py_arr[i]);
		c_sum += c_arr[i];
		cp_sum += cp_arr[i];
		py_sum += py_arr[i];
	}
	printf("----------avg---------\n");
	printf("%.1f\t%.1f\t%.1f\n", c_sum / *cnt_ptr, cp_sum / *cnt_ptr, py_sum / *cnt_ptr);
}

void search(int* cnt_ptr, int* c_arr, int* cp_arr, int* py_arr, float* avg_arr) {
	printf("검색 선택\n");
	int no;
	scanf("%d", &no);

	if (no == 0 || no > *cnt_ptr) {
		printf("존재하지 않는 학생 번호 입니다.\n");
		return;
	}

	printf("c\tcpp\tpython\tavg\n");
	printf("--------------------------\n");
	printf("%d\t%d\t%d\t%.1f\n", c_arr[no - 1], cp_arr[no - 1], py_arr[no - 1], avg_arr[no - 1]);
}

void delete(int* cnt_ptr, int* c_arr, int* cp_arr, int* py_arr, float* avg_arr) {
	printf("삭제 선택\n");
	int no;
	scanf("%d", &no);

	if (no == 0 || no > *cnt_ptr) {
		printf("존재하지 않는 학생 번호 입니다.\n");
		return;
	}

	// 순회하며 삭제 데이터보다 높은 인덱스로 덮어씌우기
	for (int i = no - 1; i < *cnt_ptr; i++) {
		c_arr[i] = c_arr[i + 1];
		cp_arr[i] = cp_arr[i + 1];
		py_arr[i] = py_arr[i + 1];
		avg_arr[i] = avg_arr[i + i];
	}

	(*cnt_ptr)--;
}