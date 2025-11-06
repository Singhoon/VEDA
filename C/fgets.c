#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char big_str[500] = "";

	while (1) {
		char buffer[80];
		fgets(buffer, sizeof(buffer), stdin);
		if (!strcmp(buffer, "end\n")) break;
		if (strlen(big_str) + strlen(buffer) > 499) break;
		strcat(big_str, buffer);
	}

	return 0;
}