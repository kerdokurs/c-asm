global main

extern printf

;;; Siin on kood
section .text

main:
  ; printf(hello_world, 10)
  ; Hello, world: 10!

  push 10
  push hello_world

  call printf

  pop eax
  pop eax

  ; return 0
  mov eax, 0
  ret

section .data
;;; '\n' = 10, l6pus null-byte
hello_world:
  db 'Hello, world: %d!', 10, 0
