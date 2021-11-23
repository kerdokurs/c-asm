CC = gcc
CFLAGS = -m32 -g

ASM = nasm
AFLAGS = -f elf

BINS =

all: $(BINS)

esimene: esimene.o esimene.c
	$(CC) $(CFLAGS) -o esimene esimene.o esimene.c

teine: teine.o teine.c
	$(CC) $(CFLAGS) -o teine teine.o teine.c

summa: summa.o summa.c
	$(CC) $(CFLAGS) -o summa summa.o summa.c

%: %.o
	@echo "[GCC]  $<"
	$(CC) $(CFLAGS) -o $@ $<
	./$@

%.o: %.asm
	@echo "[ASM]  $<"
	$(ASM) $(AFLAGS) $<

clean:
	rm -rf *.o $(BINS)

# nasm -f elf -o hello.o hello.asm
# gcc -m32 -o hello hello.o
