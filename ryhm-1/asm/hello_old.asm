; hello.asm
global main
extern printf
section .text

main:
  push hello
  call printf
  pop eax
  mov eax, 0
	ret

section .data

hello:
  db 'Hello, world!', 10, 0
