#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
// 전제 - Linked List에 동일한 데이터가 없다.
int main() {
	struct Node {
		int num;
		struct Node* next;
	} *Head, * Tail, * temp;
	Head = Tail = NULL;
	while (1) {
		temp = (struct Node*)malloc(sizeof(struct Node));
		if (temp == NULL) {
			printf("malloc failed\n");
			return 1;
		}
		// 수를 입력 받아서 링크드 리스트에 입력
		// 음수라면 입력 종료
		scanf("%d", &temp->num);
		if (temp->num < 0) {
			break;
		}
		temp->next = NULL;
		if (Head == NULL) {
			Head = Tail = temp;	// 첫번째 노드
		}
		else {
			Tail->next = temp;
			Tail = temp;
		}
	}
	// Linked List 출력
	temp = Head;
	while (temp != NULL) {
		printf("%d\n", temp->num);
		temp = temp->next;
	}
	// Linked List 삭제
	int del;
	temp = Head;
	struct Node* btemp = Head;
	printf("삭제 : ");
	scanf("%d", &del);
	while (temp) {
		if (del == temp->num) {
			if (temp == Head) {		// 삭제 노드가 첫번째 노드인 경우
				Head = Head->next;
			}
			else if (temp == Tail) {	// 마지막 노드 삭제
				btemp->next = NULL;
				Tail = btemp;
			}
			else { 					// 중간 노드 삭제
				btemp->next = temp->next;
			}
			struct Node* ctemp = temp;
			temp = temp->next;
			free(ctemp);
		}
		else {
			// 노드 이동 : btemp - 현재 노드, temp - 다음 노드로 이동
			btemp = temp;
			temp = temp->next;
		}
	}
	// Linked List 출력
	temp = Head;
	while (temp) {
		printf("%d\n", temp->num);
		temp = temp->next;
	}
	// Linked List 해제
	return 0;
}