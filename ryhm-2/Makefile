CC = gcc
CFLAGS = -std=c99 -g

bf_array: main.c bf.o mem_array.o test.o
	$(CC) $(CFLAGS) main.c bf.o mem_array.o test.o -o bf_array

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

viidad: viidad.c
	$(CC) $(CFLAGS) viidad.c -o viidad

clean:
	rm -rf *.o bf bf_array
