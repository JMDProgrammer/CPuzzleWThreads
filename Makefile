CC=gcc
CFLAGS=-I. -g -pthread -w
DEPS = wordpuzzle.h
OBJ = wordpuzzle.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

wordpuzzle: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)