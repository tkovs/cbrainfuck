#include <stdio.h>
#include "include/cbrainfuck.h"

int main() {
	char *s;
	s = interpreter("txt/code.txt", "txt/input.txt");

	if (_ERRORS_ > 0) {
		puts(_MESSAGE_);
		return 1;
	} else {
		printf ("Output: %s", s);
	}

	return 0;
}