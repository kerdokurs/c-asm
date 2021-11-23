global tervitus
extern printf

section .text

; void tervitus(void);
tervitus:
  push tere    ; paneme magasini peale viida muutujale `tere`
  call printf  ; kutsume printf
  add esp, 4   ; lisame magasini viidale 4 ehk sisuliselt eemaldame sealt pealt elemendi

  ret

section .data
tere:
  db 'Tere! (kutsuti C-st)', 10, 0
