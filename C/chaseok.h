#ifndef _CHASEOK_H_
#define _CHASEOK_H_

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 구조체 선언
typedef struct student_node{
	char name[20];
	int c;
	int cpp;
	int python;
	float avg;
	struct student_node* next;
} STUDENT;

// 함수의 반환값 :  성공하면 1 반환, 실패하면 0 반환
 /*
  입력 함수
 */
void input(int* cnt_ptr, STUDENT** HEAD, STUDENT** TAIL);

/*
 출력 함수
*/
void output(int* cnt_ptr, STUDENT** HEAD, STUDENT** TAIL);

/*
 검색 함수
*/
void search(int* cnt_ptr, STUDENT** HEAD, STUDENT** TAIL);

/*
 삭제 함수
*/
void delete(int* cnt_ptr, STUDENT** HEAD, STUDENT** TAIL);

#endif