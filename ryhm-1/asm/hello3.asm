global main

extern printf

;;; Siin on kood
section .text

;;; Main funktsioon
main:
  mov eax, 10

  ; eax - 4 baiti
  ;  ax - 2 alumist baiti
  ;  ah - teine bait
  ;  al - esimene bait

  cmp eax, 10
  je lbl_two

  cmp eax, 12

  push 0
  jmp lbl_end

lbl_two:
  push 10

lbl_end:
  push hello_world
  call printf

  pop eax
  pop eax

  ; Return 0
  mov eax, 0
  ret

;;; Siin on väärtustatud muutujad
section .data

;;; Sõne hello_world
;;; L6pus new-line ja null-byte
hello_world:
  db 'Hello, world! %d', 10, 0

