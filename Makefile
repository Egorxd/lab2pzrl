.PHONY: all clean run

MO = main.o

all: test

test: main.o operations.o bin.o oct.o hex.o
	gcc $(MO) operations.o bin.o oct.o hex.o -o test -lm

$(MO): main.c
	gcc -c main.c

operations.o: operations.c
	gcc -c operations.c

bin.o: bin.c
	gcc -c bin.c

oct.o: oct.c
	gcc -c oct.c

hex.o: hex.c
	gcc -c hex.c

run: test
	./test

clean:
	rm -rf *.o test
