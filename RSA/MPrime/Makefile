start: mprime
	rm *.o

mprime: main.o mathp.o mod.o primo.o
	gcc -g main.o mathp.o mod.o primo.o -o mprime

main.o: main.c mathp.h mod.h primo.h
	gcc -g -c main.c

mathp.o: mathp.c mathp.h
	gcc -g -c mathp.c

mod.o: mod.c mod.h
	gcc -g -c mod.c

primo.o: primo.c primo.h
	gcc -g -c primo.c