global main

extern printf
extern atoi

;;; Siin on kood
section .text

;;; Main funktsioon
;;; (argc,   argv)
;;; (esp+4, esp+8)
main:
  mov eax, [esp+4] ; argc
  mov ebx, [esp+8] ; argv ((char *)*)
  
  push test
  call atoi
  add esp, 4
  push eax
  push output
  call printf
  add esp, 8

  ; Return 0
  mov eax, 0
  ret

;;; Siin on väärtustatud muutujad
section .data

; 10 = '\n'
output:
  db '%d', 10, 0
test:
  db '5', 0

