global main

extern printf

;;; Siin on kood
section .text

;;; Main funktsioon
main:
  ; Prindi numbrid 1-st 10-ni

  ; loop <label>
  ; ecx-- ja if (ecx != 0) goto <label>

  mov ebx, 1
  mov ecx, 10
  ; printf(output, ecx);
  ;        "%d\n",   1;

  ; Saab kasutada, et kirjutada muutujasse `output`
  ; mov [output], ebx

  ; ecx, (ebx, output)
  sub esp, 8
  push output

kordus:
  mov [esp+8], ecx ; printf rikub ecx ära
  mov [esp+4], ebx

  call printf

  mov ecx, [esp+8]
  
  inc ebx

  ; loop <label>
  ; ecx--
  ; if (ecx != 0) goto <label>
  loop kordus

  add esp, 12

  ; Return 0
  mov eax, 0
  ret

;;; Siin on väärtustatud muutujad
section .data

; 10 = '\n'
output:
  db '%d', 10, 0

