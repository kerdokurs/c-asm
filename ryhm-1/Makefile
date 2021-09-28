CC = gcc
CFLAGS = -std=c99 -g

all: $(BIN)

bf: bf.c
	$(CC) $(CFLAGS) bf.c -o bf

bf_array: main.c mem_array.o test.o bf.o
	$(CC) $(CFLAGS) main.c mem_array.o test.o bf.o -o $@

viidad: viidad.c
	$(CC) $(CFLAGS) viidad.c -o viidad

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(BIN)
