#include <stdlib.h>
#include <stdio.h>
#include "cbrainfuck.h"

void open_files(FILE** code_file, char* code_file_name, FILE** input_file, char* input_file_name)
{
	(*code_file) = fopen(code_file_name, "r");

	if ((*code_file) != NULL)
	{
		(*input_file) = fopen(input_file_name, "r");
		if ((*input_file) == NULL)
		{
			fclose((*code_file));
			printf ("\nCouldn't open input file [%s]\n", input_file_name);
			scanf ("%*c");
			exit(1);
		}
	}
	else
	{
		printf ("\nCouldn't open code file [%s]\n", code_file_name);
		scanf ("%*c");
		exit(1);
	}
}

void initialize(List *list)
{
	list->value = 0;
	list->next = NULL;
	list->prev = NULL;
}

void create(List *list)
{
	List *newlist;

	newlist = (List *) malloc (sizeof(List));
	newlist->value = 0;
    newlist->next = NULL;

	newlist->prev = list;
	list->next = newlist;
}

void liberate(List *list)
{
	static char i = 0;
	if (i == 0)
	{
		while (list->prev != NULL)
		{
			list = list->prev;
		}
	}

	if (list != NULL)
	{
		liberate(list->next);
		free(list);
	}
}

void interpreter(char* code_file_name, char* input_file_name)
{
	FILE *fcode = NULL;
	FILE *finput = NULL;
	int *brackets = NULL;
	List *fuckinglist = NULL;
	char c; //
	short int count = 0; // Number of scans
	short int length = 0; // Number of bracket '['

	brackets = (int *) malloc (sizeof(int));
	
	open_files(&fcode, code_file_name, &finput, input_file_name);

	fuckinglist = (List *) malloc (sizeof(List));
	initialize(fuckinglist);

	while(!feof(fcode))
	{
		fscanf (fcode, "%c", &c);
		count++;

		switch(c)
		{
			case '+':
				fuckinglist->value++;
				break;

			case '-':
				fuckinglist->value--;
				break;

			case '>':
				if (fuckinglist->next == NULL)
				{
					create(fuckinglist);
				}
				fuckinglist = fuckinglist->next;
				break;

			case '<':
				fuckinglist = fuckinglist->prev;
				break;

			case '.':
				printf ("%c", fuckinglist->value);
				break;

			case ',':
				fscanf (finput, "%c", &fuckinglist->value);
				break;

			case '[':
				length++;
				brackets = (int *) realloc (brackets, length * sizeof(int));
				brackets[length-1] = count;
				break;

			case ']':
				if (fuckinglist->value > 0)
				{
					fseek(fcode, brackets[length-1], SEEK_SET);
					count = brackets[length-1];
				}
				else if (fuckinglist->value == 0)
				{
					length--;
					brackets = (int *) realloc (brackets, length * sizeof(int));
				}
				break;
		}
	}

	liberate(fuckinglist);
	fclose(fcode);
	fclose(finput);
}