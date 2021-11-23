global main

extern printf

;;; Siin on kood
section .text

;;; Main funktsioon
;;; (argc,   argv)
;;; (esp+4, esp+8)
main:
  mov eax, [esp+4] ; argc
  mov ebx, [esp+8] ; argv
  mov ecx, 0       ; loendur

kordus:
  ; argv[i]
  ; int ebx[5];
  ; *(ebx + 1) == ebx[1]
  mov edi, [ebx+ecx*4] ; *(argv + ecx*4)

  ; eax ja ecx rikutakse ära, peame meelde jätma
  push eax
  push ecx

  push edi
  push output

  call printf

  ; neist väärtustest suva
  pop eax ; < output
  pop eax ; < edi

  ; tahame neid väärtuseid tagasi
  pop ecx
  pop eax

  inc ecx
  cmp ecx, eax
  jne kordus

  ; Return 0
  mov eax, 0
  ret

;;; Siin on väärtustatud muutujad
section .data

; 10 = '\n'
output:
  db '%s', 10, 0

