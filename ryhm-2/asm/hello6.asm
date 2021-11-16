global main

extern printf

;;; Siin on kood
section .text

main:
  ; printf("%d\n", num);

  mov ebx, 5 ; V2limine loendur

reset_inner:
  mov ecx, 1 ; Sisemine loendur

  ; printf("%d\n", ebx++);
  ; ebx <= 10
loop:
  push ebx
  push ecx
  push output
  call printf
  pop eax
  pop ecx
  pop ebx

  ; add ebx, 1
  inc ecx

  cmp ecx, 10
  ; jg end
  ; jmp loop
  jle loop

  dec ebx
  cmp ebx, 0
  jg reset_inner

  ; return 0
  mov eax, 0
  ret

section .data
;;; '\n' = 10, l6pus null-byte
output:
  db '%d', 10, 0
