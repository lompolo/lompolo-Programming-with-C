program: program.o io.o
	gcc program.o io.o -o program -std=c99 -Wall -pedantic
program.o: program.c io.h
	gcc program.c -c -std=c99 -Wall -pedantic
io.o: io.c io.h
	gcc io.c -c -std=c99 -Wall -pedantic

clean:
	-rm -f program.o
	-rm -f io.o