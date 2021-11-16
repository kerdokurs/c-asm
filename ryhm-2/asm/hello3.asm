global main

extern printf

;;; Siin on kood
section .text

main:
  mov eax, 10
  cmp eax, 10
  ; je, jne, jl, jg, jge
  je eq_lbl

  push 0
  jmp end_lbl

eq_lbl:
  push 1

end_lbl:
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
  db 'test: %d', 10, 0
