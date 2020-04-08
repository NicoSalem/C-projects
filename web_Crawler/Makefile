CC=gcc
CFLAGS=-I.
DEPS = LinkedList.h main.h
OBJ = main.o LinkedList.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

crawler: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)