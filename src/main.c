#include <stdio.h>
#include "../header/cbrainfuck.h"

int main() {
	char *r;
	r = interpreter("txt/code.txt", "txt/input.txt");
	printf("%s", r);

	return 0;
}
