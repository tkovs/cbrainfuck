all: cbrainfuck

cbrainfuck.o: source/cbrainfuck.c
	gcc -O -c source/cbrainfuck.c -o cbrainfuck.o

main.o:    main.c
	gcc -O -c main.c -o main.o

cbrainfuck: cbrainfuck.o main.o
	gcc -O -o cbrainfuck cbrainfuck.o main.o

clean:
	-rm -f cbrainfuck.o main.o cbrainfuck
