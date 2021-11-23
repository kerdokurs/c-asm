global main

extern printf

;;; Siin on kood
section .text

; eax, ebx, ecx, edx

; |  |  |  |  |
; |    eax    |
;       |  ax | 
;       |ah|al|

; main(argc, argv)
main:
  mov eax, [esp+4] ; argc
  mov ebx, [esp+8] ; argv *(esp+8)
  mov ecx, 0       ; loendur

loop:
  mov edi, [ebx+ecx*4] ; argv[ecx] v *(argv + ecx)
  push eax
  push ecx
  push edi
  push out
  call printf
  add esp, 8
  pop ecx
  pop eax
  
  inc ecx
  cmp ecx, eax
  jne loop

  ; return 0
  mov eax, 0
  ret

section .data
;;; '\n' = 10, l6pus null-byte
test_out:
  db '%d', 10, 0
out:
  db '%s', 10, 0
