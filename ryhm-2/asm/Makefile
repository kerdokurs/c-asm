CC = gcc
CFLAGS = -m32

ASM = nasm
AFLAGS = -f elf

BINS = hello

all: $(BINS)

esimene: esimene.c esimene.o
	$(CC) $(CFLAGS) -o esimene esimene.c esimene.o

teine: teine.c teine.o
	$(CC) $(CFLAGS) -o teine teine.c teine.o

summa: summa.c summa.o
	$(CC) $(CFLAGS) -o summa summa.c summa.o

summa2: summa2.c summa2.o
	$(CC) $(CFLAGS) -o summa2 summa2.c summa2.o

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
