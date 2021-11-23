global main
extern tervitus

section .text
main:
  call tervitus

  ; return 0
  mov eax, 0
  ret
