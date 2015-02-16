#ifndef CBRAINFUCK_H
#define CBRAINFUCK_H

#include <stdlib.h>

/******************** WELCOME! *********************
** Header of functions implemented in cbrainfuck.c
** that serve to manage a doubly linked list with
** specific roles to interprete a brainfuck code.
****************************************************/



/********************* mylist **********************
** Struct of my list
** value: a value between 0 and 255 (default = 0)
** next: pointer to next element (default = NULL)
** prev: pointer to previous element (default = NULL)
*/

typedef struct mylist List;
struct mylist {
	char value;
	List *next;
	List *prev;
};

/******************* open_files ********************
** This function opens two files and the files, they
** are the brainfuck code and input from user.
**
** code_file: pointer to pointer of brainfuck code file
** code_file_name: brainfuck code file's name
** input_file: pointer to pointer of input file
** input_file_name: input file's name** 
** 
*/

void open_files(FILE** code_file, char* code_file_name, FILE** input_file, char* input_file_name);

#endif