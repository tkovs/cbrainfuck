#include <stdlib.h>
#include "cbrainfuck.h"

void open_files(FILE** code_file, char* code_file_name, FILE** input_file, char* input_file_name)
{
	(*code_file) = fopen(code_file_name, "r");

	if ((*code_file) != NULL)
	{
		(*input_file) = fopen(input_file_name, "r");
		{
			if ((*input_file) != NULL)
			{
				fclose(code_file);
				printf ("\nCouldn't open input file [%s]\n", input_file_name);
				scanf ("%*c");
				exit(1);
			}
		}
	}
	else
	{
		printf ("\nCouldn't open code file [%s]\n", code_file_name);
		scanf ("%*c");
		exit(1);
	}
}