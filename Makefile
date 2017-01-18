CC=gcc
CFLAGS= -g -pedantic -Wall -Werror

VPATH=src

SRC=huffman.c tree.c main.c queue.c
OBJ=huffman.o tree.o main.o queue.o
BIN=huffman

all :	$(BIN)

$(BIN) : $(OBJ)
	$(CC) $^ -o $@

huffman.o: huffman.c
	$(CC) -c $(CFLAGS) $<

tree.o:	tree.c
	$(CC) -c $(CFLAGS) $<

main.o:	main.c
	$(CC) -c $(CFLAGS) $<

queue.o: queue.c
	$(CC) -c $(CFLAGS) $<

check :
	./$(BIN)

clean :
	$(RM) $(BIN) $(OBJ)
