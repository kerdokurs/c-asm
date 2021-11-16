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

loop:
  push ebx
  push output

  call printf

  pop eax
  pop eax

  ; add ebx, 1
  inc ebx

  cmp ebx, 10
  ; jg end
  ; jmp loop
  jle loop

; end:

  ; Return 0
  mov eax, 0
  ret

;;; Siin on väärtustatud muutujad
section .data

; 10 = '\n'
output:
  db '%d', 10, 0

