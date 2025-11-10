#include <iostream>

using namespace std;

void sum_int(int op1, int op2) {
	const int var11 = 10;
	const int var12 = op1 + 10;
	const int var13 = op1 + op2;
	constexpr int var14 = 20;

	constexpr int var15 = var14 + 15;
	//constexpr int var16 = op1 + op2; -> ¾ÈµÊ
}

int main() {
	return 0;
}