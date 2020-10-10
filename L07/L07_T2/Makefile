program: program.o io.o
	gcc program.o lista.o -o program -std=c99 -Wall -pedantic
program.o: program.c lista.h
	gcc program.c -c -std=c99 -Wall -pedantic
io.o: lista.c lista.h
	gcc lista.c -c -std=c99 -Wall -pedantic

clean:
	-rm -f program.o
	-rm -f lista.o