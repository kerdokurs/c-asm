CC = gcc
CFLAGS = -std=c99 -g

BINS=queue

all: $(BINS)

bf: bf.c
	$(CC) $(CFLAGS) bf.c -o bf

bf_array: main.c mem_array.o test.o bf.o
	$(CC) $(CFLAGS) main.c mem_array.o test.o bf.o -o $@

bf_list: main.c mem_list.o mem.h list.o test.o bf.o
	$(CC) $(CFLAGS) main.c mem_list.o list.o test.o bf.o -o $@

bf_ll: main.c mem_ll.o mem.h list.o test.o bf.o
	$(CC) $(CFLAGS) main.c mem_ll.o list.o test.o bf.o -o $@

main_mag: main_mag.c magasin.o
	$(CC) $(CFLAGS) main_mag.c magasin.o -o main_mag

test_mag: test_mag.c magasin.o test.h magasin.h
	$(CC) $(CFLAGS) test_mag.c magasin.o -o test_mag

viidad: viidad.c
	$(CC) $(CFLAGS) viidad.c -o viidad

puud: puud.c
	$(CC) $(CFLAGS) $< -o $@

failid: failid.c
	$(CC) $(CFLAGS) failid.c -o failid

dyn: dyn.c list.o
	$(CC) $(CFLAGS) dyn.c list.o -o dyn

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(BIN)
