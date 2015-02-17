#include <stdio.h>
#include <stdlib.h>
#include "../header/cbrainfuck.h"

int main() {
	List *fuckinglist = NULL;

	fuckinglist = (List *) malloc (sizeof(List));
	initialize(fuckinglist);

	create(fuckinglist);
	fuckinglist = fuckinglist->next;
	create(fuckinglist);
	fuckinglist = fuckinglist->next;
	create(fuckinglist);
	fuckinglist = fuckinglist->next;
	create(fuckinglist);
	fuckinglist = fuckinglist->next;
	create(fuckinglist);
	fuckinglist = fuckinglist->next;
	create(fuckinglist);
	fuckinglist = fuckinglist->next;
	create(fuckinglist);
	fuckinglist = fuckinglist->next;
	create(fuckinglist);

	printf ("fuckinglist.value = [%d]\n", fuckinglist->value);

	while (fuckinglist->prev != NULL)
    	fuckinglist = fuckinglist->prev;
	liberate(fuckinglist);
	return 0;
}
