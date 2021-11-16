global main

extern printf

;;; Siin on kood
section .text

main:
  ; printf("%d\n", num);

  mov ebx, 1 ; Loendur

  ; printf("%d\n", ebx++);
  ; ebx <= 10

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

  ; return 0
  mov eax, 0
  ret

section .data
;;; '\n' = 10, l6pus null-byte
output:
  db '%d', 10, 0
