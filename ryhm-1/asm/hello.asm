global main

extern printf

;;; Siin on kood
section .text

;;; Main funktsioon
main:
  ; Paneme viida hello_world muutujale stacki peale
  push hello_world

  ; Kutsume printf
  call printf
  ; eax sisaldab prinditud karakterite arvu

  ; Votame stacki pealt muutuja 2ra
  pop eax

  ; Return 0
  mov eax, 0
  ret

;;; Siin on väärtustatud muutujad
section .data

;;; Sõne hello_world
;;; L6pus new-line ja null-byte
hello_world:
  db 'Hello, world!', 10, 0

