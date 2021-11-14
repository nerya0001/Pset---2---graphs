CC=gcc
AR=ar
OBJECTS_MAIN=main.o
FLAGS= -Wall -g

all: libmine.a connections

libmine.a: my_mat.o
		$(AR) -rcs libmine.a my_mat.o

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c -lm

main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c

connections: $(OBJECTS_MAIN) libmine.a
	$(CC) $(FLAGS) -o connections $(OBJECTS_MAIN) libmine.a -lm


.PHONY: clean all

clean:
	rm -f *.o *.a connections
