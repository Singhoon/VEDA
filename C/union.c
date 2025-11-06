#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	union {
		unsigned int ip;
		unsigned char addr[4];
	} ipaddr;

	ipaddr.ip = 0x12345678;
	for (int i = 0; i < 4; i++) {
		printf("%x\t", ipaddr.addr[i]);
	}
	
}