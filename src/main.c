#include <stdio.h>
#include "../header/cbrainfuck.h"

int main() {
	FILE *fcode = NULL;
	FILE *finput = NULL;
	List *fuckinglist = NULL;
	char *cname = "txt/code.txt";
	char *iname = "txt/input.txt";

	fuckinglist = (List *) malloc (sizeof(List));
	initialize(fuckinglist);

	printf ("fuckinglist.value = [%d]\n", fuckinglist->value);

	open_files(&fcode, cname, &finput, iname);

	free(fuckinglist);
	fclose(finput);
	fclose(fcode);
	return 0;
}