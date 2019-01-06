/******************** WELCOME! **********************
** Header of functions implemented in cbrainfuck.c
** that serve to manage a doubly linked list with
** specific roles to interprete a brainfuck code
****************************************************/

#ifndef CBRAINFUCK_INCLUDED
#define CBRAINFUCK_INCLUDED

/********************* symbols **********************
** symbols that represents the brainfuck operations
**
** >: moves the pointer to the next cell
** <: moves the pointer to the previous cell
** +: adds 1 to the cell
** -: subtracts 1 from the cell
** #: the characters after this symbol are considered a comment
** .: print the current cell's value to stdout
** ,: reads a input of user and sends to the current cell
** [: open a loop using the current cell's value
** ]: closes the loop if the current cell's value is 0
*/

#define NEXT '>'
#define PREVIOUS '<'
#define INCREMENT '+'
#define DECREMENT '-'
#define COMMENT '#'
#define PRINT '.'
#define SCAN ','
#define OPENLOOP '['
#define CLOSELOOP ']'

/******************* my constants ******************
** Constants to save information
**
** _ERRORS_: 0 to nothing 1 or more to error
** _MESSAGE_: error message
*/

int _ERRORS_;
char *_MESSAGE_;

/********************** mylist **********************
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

/******************** open_files ********************
** This function opens two files and the files, they
** are the brainfuck code and input from user
**
** Return 0 to sucess and 1 to failure
**
** code_file: pointer to pointer of brainfuck code file
** code_file_name: brainfuck code file's name
** input_file: pointer to pointer of input file
** input_file_name: input file's name** 
** 
*/

int open_files (FILE** code_file, char* code_file_name, FILE** input_file, char* input_file_name);

/******************** initialize ********************
** This function just initializes the list data
**
** element: the list made in main.c
**
** Initialize with the following values:
** value = 0
** next = NULL
** prev = NULL
*/

void initialize (List *element);

/********************** create **********************
** This function add a new element in the list
** 
** element: the list made in main.c
*/

void create (List *element);

/********************** liberate ***********************
** This function frees all memory used by the list using
** recursion.
** 
** element: the list made in main.c
*/

void liberate (List *element);

/******************** intepreter ********************
** This function interprets the brainfuck code file and
** returns the string result.
** 
*/

char* interpreter (char* code_file_name, char* input_file_name);

/********************** report **********************
** This function writes in the global variable MESSAGE any
** error from program.
** 
*/

void report (char *msg);

#endif
