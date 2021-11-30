global main
extern printf

section .text

; (x, y)
korruta:
  ; proloog
  push ebp
  mov ebp, esp

  mov eax, [esp+8] ; x
  mov ecx, [esp+12] ; y
  mov edx, 0
  mul ecx

  ; epiloog
  mov esp, ebp
  pop ebp

  ret

main:
  push 5
  push 10
  call korruta
  add esp, 8 ; pop x2

  push eax
  push fmt_str
  call printf
  add esp, 8

  ; return 0
  mov eax, 0
  ret

section .data
fmt_str:
  db '%d', 10, 0
