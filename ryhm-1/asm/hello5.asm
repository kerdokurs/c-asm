global main

extern printf

;;; Siin on kood
section .text

;;; Main funktsioon
main:
  ; Prindi numbrid ühest 10-ni

  mov ebx, 1
  ; printf(output, ecx);
  ;        "%d\n",   1;

  ; Saab kasutada, et kirjutada muutujasse `output`
  ; mov [output], ebx

  sub esp, 4
  push output

loop:
  ; push ebx
  ; TODO: Liiguta ebx outputi ette (mitte stacki l6ppu)

  call printf

  ; add ebx, 1
  inc ebx

  cmp ebx, 10
  ; jg end
  ; jmp loop
  jle loop

; end:

  add esp, 8  

  ; Return 0
  mov eax, 0
  ret

;;; Siin on väärtustatud muutujad
section .data

; 10 = '\n'
output:
  db '%d', 10, 0

