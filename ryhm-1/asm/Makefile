CC = gcc
CFLAGS = -m32

ASM = nasm
AFLAGS = -f elf

BINS = hello4

all: $(BINS)

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
