CC = gcc
CFLAGS = -std=c99 -g

all: $(BIN)

bf: bf.c
	$(CC) $(CFLAGS) bf.c -o bf

bf_array: main.c mem_array.o test.o bf.o
	$(CC) $(CFLAGS) main.c mem_array.o test.o bf.o -o $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(BIN)
