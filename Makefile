CC=gcc
CFLAGS= -g -pedantic -Wall -Werror

SRC=huffman.c tree.c main.c queue.c
OBJ=$(.c=.o)
BIN=huffman

all :
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

check :
	./$(BIN)

clean :
	$(RM) $(BIN) $(OBJ)
