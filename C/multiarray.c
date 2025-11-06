#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
// 5명 이름 입력 후에 검색한다. 검색할 이름은 따로 입력받는다. 후에 입력받아서 있는지 없는지 검사. 있으면 몇번째 위치에 있는지 확인
int main() {

	char names[5][10];
	char search[10];
	for (int i = 0; i < 5; i++) {
		fgets(names[i], sizeof(names[0]), stdin);
		names[i][strcspn(names[i], "\n")] = '\0';
	}

	printf("검색할 이름을 쓰세요 : ");
	fgets(search, sizeof(search), stdin);
	search[strcspn(search, "\n")] = '\0';

	int found = 0;
	int position = 0;
	for (int i = 0; i < 5; i++) {
		if (strcmp(search, names[i]) == 0) {
			found = 1;
			position = i + 1;
		}
	}
	if (found) printf("%s(은)는 %d번째 위치에 있습니다.", search, position);
	else printf("%s(은)는 배열에 없습니다.", search);

	return 0;
}

