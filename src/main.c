#include <stdio.h>
#include "../header/cbrainfuck.h"

int main() {
	FILE *finput, *fcode;
	char *iname = "../txt/input.txt";
	char *cname = "../txt/code.txt";

	open_files(&fcode, cname, &finput, iname);

	fclose(finput);
	fclose(fcode);
	return 0;
}