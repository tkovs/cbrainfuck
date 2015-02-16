all:CBRAINFUCK
	gcc src/main.c header/cbrainfuck.o -o main.a
CBRAINFUCK:
	gcc -c header/cbrainfuck.c