global main

extern printf

;;; Siin on kood
section .text

;;; Main funktsioon
main:
  ; printf(hello_world, 10);

  push 10
  ; Paneme viida hello_world muutujale stacki peale
  push hello_world

  ; Kutsume printf
  call printf
  ; eax sisaldab prinditud karakterite arvu

  ; Votame stacki pealt muutuja 2ra
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

