CC=gcc
AR=ar
FLAGS=-Wall -g

all: libmine.a connections

libmine.a: my_mat.o
	$(AR) -rcs libmine.a my_mat.o

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c
main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c

connections: main.o libmine.a
	$(CC) $(FLAGS) -o connections main.o libmine.a


.PHONY: clean all

clean:
	rm -f *.o *.a connections
