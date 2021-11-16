global main

extern printf

;;; Siin on kood
section .text

main:
  ; printf(fmt, ...)

  push hello_world

  call printf
  ; ecx, ebx, eax

  pop eax

  ; return 0
  mov eax, 0
  ret

section .data
;;; '\n' = 10, l6pus null-byte
hello_world:
  db 'Hello, world!', 10, 0
