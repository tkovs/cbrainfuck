#include <stdio.h>
#include <stdlib.h>
#include "../include/cbrainfuck.h"

int open_files(FILE** code_file, char* code_file_name, FILE** input_file, char* input_file_name)
{
	(*code_file) = fopen(code_file_name, "r");

	if ((*code_file) != NULL)
	{
		(*input_file) = fopen(input_file_name, "r");
		if ((*input_file) == NULL)
		{
			fclose((*code_file));
			report ("Couldn't open input file");
			return 1;
		}
	}
	else
	{
		report ("Couldn't open code file");
		return 1;
	}

	return 0;
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
	initialize(newlist);

	newlist->prev = list;
	list->next = newlist;
}

void liberate(List *list)
{
	if (list != NULL)
	{
		liberate(list->next);
		free(list);
	}
}

char* interpreter(char* code_file_name, char* input_file_name)
{
	_ERRORS_ = 0;
	free(_MESSAGE_);
	_MESSAGE_ = NULL;

	FILE *fcode = NULL;
	FILE *finput = NULL;
	int *brackets = NULL;
	List *fuckinglist = NULL;
	char c; // to scan
	char *result; // Message from code
	short int countscan = 0; // Number of scans
	short int length = 0; // Number of bracket '['
	short int countpoint = 1; // Number of '.'

	if (open_files(&fcode, code_file_name, &finput, input_file_name) == 1)
	{
		return NULL;
	}

	result = (char *) malloc (countpoint * sizeof(char));
	result[countpoint-1] = '\0';
	brackets = (int *) malloc (sizeof(int));
	fuckinglist = (List *) malloc (2 * sizeof(List));
	initialize(fuckinglist);

	while((c = fgetc(fcode)) != EOF)
	{
		countscan++;

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
				if (fuckinglist->value == 0) break;
				result[countpoint-1] = fuckinglist->value;
				countpoint++;
				result = (char *) realloc (result, countpoint * sizeof(char));
				result[countpoint-1] = '\0';
				break;

			case ',':
				fscanf (finput, "%c", &fuckinglist->value);
				break;

			case '[':
				if (fuckinglist->value == 0) {
					int nested = 1;
					while(nested) {
						char c1;
						fscanf (fcode, "%c", &c1);
						countscan++;
						if (c1 == '[') nested++;
						if (c1 == ']') nested--;
					}
				    break;
				}

				length++;
				brackets = (int *) realloc (brackets, length * sizeof(int));
				brackets[length-1] = countscan;
				break;

			case ']':
				if (fuckinglist->value != 0)
				{
					fseek(fcode, brackets[length-1], SEEK_SET);
					countscan = brackets[length-1];
				}
				else
				{
					length--;
					brackets = (int *) realloc (brackets, length * sizeof(int));
				}
				break;
		}
	}


	while (fuckinglist->prev != NULL)
		fuckinglist = fuckinglist->prev;
	liberate(fuckinglist);

	fclose(fcode);
	fclose(finput);

	result[countpoint-1] = '\0';
	return result;
}

void report(char *msg) {
    _ERRORS_ = 1;
    _MESSAGE_ = msg;
}
