#include "classtemplate.h"

int main() {

	data_package<int, double> template_inst1(5, 10.5);
	data_package<string, int> template_inst2("¹®ÀÚ¿­", 10);

	template_inst1.print_out_element();
	template_inst2.print_out_element();

	return 0;
}