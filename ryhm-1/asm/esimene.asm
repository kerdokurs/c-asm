global tervitus
extern printf

section .text

tervitus:
  push tere
  call printf
  add esp, 4 ; alternatiivne pop

  ret

section .data
tere:
  db 'Tere! (kutsuti C-st)', 10, 0
