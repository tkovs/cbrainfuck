/******************** WELCOME! *********************
** Header of functions implemented in cbrainfuck.c
** that serve to manage a doubly linked list with
** specific roles to interprete a brainfuck code
****************************************************/

#ifndef CBRAINFUCK_INCLUDED
#define CBRAINFUCK_INCLUDED

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
** are the brainfuck code and input from user
**
** code_file: pointer to pointer of brainfuck code file
** code_file_name: brainfuck code file's name
** input_file: pointer to pointer of input file
** input_file_name: input file's name** 
** 
*/

void open_files(FILE** code_file, char* code_file_name, FILE** input_file, char* input_file_name);

/******************* initialize ********************
** This function just initializes the list data
**
** element: the list made in main.c
**
** Initialize with the following values:
** value = 0
** next = NULL
** prev = NULL
*/

void initialize(List *element);

/********************* create **********************
** This function add a new element in the list
** 
** element: the list made in main.c
*/

void create(List *element);

/********************** liberate ***********************
** This function frees all memory used by the list using
** recursion.
** 
** element: the list made in main.c
*/

void liberate(List *element);

#endif
