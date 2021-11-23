; hello.asm
global main
extern printf
section .text

main:
  mov ecx, 1           ; counter

  mov edx, [esp+4]     ; argc
  mov eax, [esp+8]     ; argv

loop:
  push edx
  push eax
  push ecx
  mov edi, ecx
  mul edi, 4
  add edi, [eax]
  push edi ; argv[ecx]
  push hello
  call printf
  pop ebx
  pop ebx
  pop ecx
  pop eax
  pop edx

  inc ecx
  cmp ecx, edx
  jne loop

end:

  mov eax, 0
	ret

section .data

hello:
  db 'Hello, %s!', 10, 0
