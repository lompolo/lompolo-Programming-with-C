program: program.o muisti.o io.o
	gcc program.o muisti.o io.o -o program -std=c99 -Wall -pedantic
program.o: program.c muisti.h io.h
	gcc program.c -c -std=c99 -Wall -pedantic
muisti.o: muisti.c muisti.h
	gcc muisti.c -c -std=c99 -Wall -pedantic
io.o: io.c io.h
	gcc io.c -c -std=c99 -Wall -pedantic

clean:
	-rm -f program.o
	-rm -f io.o
	-rm -f muisti.o