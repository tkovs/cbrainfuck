#include <stdio.h>
#include <stdlib.h>
#include "../header/cbrainfuck.h"

int main() {
	List *fuckinglist = NULL;

	fuckinglist = (List *) malloc (sizeof(List));
	initialize(fuckinglist);

	create(fuckinglist);
	create(fuckinglist);

	printf ("fuckinglist.value = [%d]\n", fuckinglist->value);

	liberate(fuckinglist);
	return 0;
}
