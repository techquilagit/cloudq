global Recv
%if BITS == 64
Recv:
    mov r10, rcx
    xor r8, r8
    xor r9, r9
    mov rax, 45
    syscall
    ret
%elif BITS == 32
Recv:
    push ebx
    push esi
    push edi
    mov ebx, [esp + 16]
    mov ecx, [esp + 20]
    mov edx, [esp + 24]
    mov esi, [esp + 28]
    xor edi, edi
    xor ebp, ebp
    mov eax, 125
    int 0x80
    pop edi
    pop esi
    pop ebx
    ret
%endif