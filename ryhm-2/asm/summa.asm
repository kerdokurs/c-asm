;;; summa.asm
global summa

section .text

summa:
  ; `ebx` registrit ei tohi muuta!
  ; v6i tuleb salvestada ja taastada
  mov eax, [esp+4] ; x
  mov ecx, [esp+8] ; y
  add eax, ecx
  ret
