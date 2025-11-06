#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "type.h"
#define DEBUG
#define bit1(n, b) ((n)&((1)<<(b)))? 1:0
#define bitset(n, b) n=((n)|(1<<(b-1)))
#define bitflip(n,b) n=((n)^(1<<(b-1)))
#define max(n1,n2) ((n1)>(n2))? (n1):(n2) // 괄호를 명확히 하자. type 체크도 안함

int main() {
	int num = 10;

	//result1 = bit1(num, 8);
	//result2 = bit1(num, 3);

#ifdef DEBUG
	printf("%d\n", num);
#endif // DEBUG

	bitflip(num, 4);

	printf("%x\n", num);

	func();
	
	return 0;
}