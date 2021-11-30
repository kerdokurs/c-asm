global main
extern printf
extern atoi

section .text

; (x, y)
korruta:
  ; proloog
  push ebp
  mov ebp, esp

  mov eax, [esp+8] ; x
  mov ecx, [esp+12] ; y
  mov edx, 0
  mul ecx

  ; epiloog
  mov esp, ebp
  pop ebp

  ret

; (argc, argv)
main:
  ;; teeme eelduse, et argc >= 3
  mov edx, [esp+8] ; argv ((char *)*)
  mov ecx, [edx+4] ; argv[1]
  push edx         ; atoi rikub EDX registri ära
  push ecx         ; stackil esimene argument (str)
  call atoi        ; atoi(argv[1])
  add esp, 4       ; stack taastatud
  pop edx          ; taastame EDX registri
  push eax         ; stackil atoi(argv[1])
  mov ecx, [edx+8] ; argv[2]
  push ecx         ; stackil teine argument (str)
  call atoi        ; atoi(argv[2])
  add esp, 4       ; stack taastatud
  push eax         ; stackil atoi(argv[1]), atoi(argv[2])
  call korruta     ; korruta(atoi(argv[1]), atoi(argv[2])
  add esp, 8       ; stack taastatud
  push eax         ; stackil korruta(...)
  push fmt_str     ; stackil fmt_str
  call printf      ; printf(fmt_str, korruta(...))
  add esp, 8       ; stack taastatud

  ; return 0
  mov eax, 0
  ret

section .data
fmt_str:
  db '%d', 10, 0
