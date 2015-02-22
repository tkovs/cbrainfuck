#include <stdio.h>
#include <stdlib.h>

#include "include/cbrainfuck.h"

int main(int argc, char ** argv) {
	char *s;
	s = interpreter(argv[1], argc>2?argv[2]:"/dev/stdin");

	if (_ERRORS_ > 0) {
		fprintf(stderr, "%s\n", _MESSAGE_);
		return 1;
	} else {
		printf ("%s", s);
		free(s);
	}

	return 0;
}
