CC = gcc
CFLAGS = -std=c99 -g

bf_array: main.c bf.o mem_array.o test.o list.o
	$(CC) $(CFLAGS) main.c bf.o mem_array.o test.o list.o -o bf_array

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

viidad: viidad.c
	$(CC) $(CFLAGS) viidad.c -o viidad

dyn: dyn.c list.o
	$(CC) $(CFLAGS) dyn.c list.o -o dyn

clean:
	rm -rf *.o bf bf_array
