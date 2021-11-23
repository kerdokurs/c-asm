global summa

section .text

; void summa(int *x, int *y, int n)
; *x++ = *y++
summa:
  ; proloog
  ; push ebp
  ; mov ebp, esp

  mov eax, [esp+4]  ; x
  mov ecx, [esp+8]  ; y
  mov edx, [esp+12] ; n
  push ebx
  mov ebx, eax

kordus:
  mov eax, [ebx] ; temp = *x
  add eax, [ecx] ; temp += *y
  mov [ebx], eax ; *x = temp
  add ebx, 4     ; x++
  add ecx, 4     ; y++
  dec edx        ; n--
  cmp edx, 0     ; n == 0
  jne kordus     ; n != 0: goto kordus

  pop ebx
  mov eax, 0

  ; TODO: fix seg fault
  ; epiloog
  ; mov esp, ebp
  ; pop ebp

  ret
