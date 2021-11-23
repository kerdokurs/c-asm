;;; summa.asm
; TODO kes on selle tehtud saanud: implemeneteeri funktsioon, mis tootab nagu void *memcpy(void *dst, void *src, int n)

global summa
extern printf

section .text

; int summa(x, y)
summa:
  ; proloog
  push ebp
  mov ebp, esp
  
  mov eax, [ebp+8]  ; x
  ; EBX-d ei tohi puutuda
  mov ecx, [ebp+12] ; y

  add eax, ecx

  ; epiloog
  mov esp, ebp
  pop ebp

  ret

section .data
debug:
  db '%d', 10, 0
